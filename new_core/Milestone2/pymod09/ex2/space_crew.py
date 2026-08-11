#!/usr/bin/env python3

from __future__ import annotations
from enum import Enum
from datetime import datetime
from pydantic import BaseModel, Field, model_validator, ValidationError


class Rank(str, Enum):
    CADET = 'cadet'
    OFFICER = 'officer'
    LIEUTENANT = 'lieutenant'
    CAPTAIN = 'captain'
    COMMANDER = 'commander'


class CrewMember(BaseModel):
    member_id: str = Field(min_length=3, max_length=10)
    name: str = Field(min_length=2, max_length=50)
    rank: Rank
    age: int = Field(ge=18, le=80)
    specialization: str = Field(min_length=3, max_length=30)
    years_experience: int = Field(ge=0, le=50)
    is_active: bool = Field(default=True)


class SpaceMission(BaseModel):
    mission_id: str = Field(min_length=5, max_length=15)
    mission_name: str = Field(min_length=3, max_length=100)
    destination: str = Field(min_length=3, max_length=50)
    launch_date: datetime
    duration_days: int = Field(ge=1, le=3650)
    crew: list[CrewMember] = Field(min_length=1, max_length=12)
    mission_status: str = Field(default='planned')
    budget_millions: float = Field(ge=1.0, le=10000.0)

    @model_validator(mode='after')
    def validator(self) -> 'SpaceMission':
        if not self.mission_id.startswith('M'):
            raise ValueError("Mission ID must start with 'M'")
        has_leader = any(
            member.rank in (Rank.COMMANDER, Rank.CAPTAIN)
            for member in self.crew
        )
        if not has_leader:
            raise ValueError("Must have at least one Commander or Captain")
        if self.duration_days > 365:
            experienced_count = sum(
                1 for member in self.crew if member.years_experience >= 5
            )
            if experienced_count / len(self.crew) < 0.5:
                raise ValueError(
                    "Long missions (> 365 days) need 50% experienced crew"
                    " (5+ years)")
        if not all(member.is_active for member in self.crew):
            raise ValueError("All crew members must be active")
        return self


def main() -> None:
    print(" Space Mission Crew Validation")
    print("=======================================")
    print("Valid mission created:")
    mission_crew = [
        CrewMember(
            member_id="HEV001",
            name="Gordon Freeman",
            rank=Rank.CAPTAIN,
            age=27,
            specialization="Theoretical Physics & Crowbar",
            years_experience=10,
            is_active=True
        ),
        CrewMember(
            member_id="HECU777",
            name="Adrian Shephard",
            rank=Rank.COMMANDER,
            age=22,
            specialization="Hazard Environment Combat",
            years_experience=7,
            is_active=True
        ),
        CrewMember(
            member_id="SEC404",
            name="Barney Calhoun",
            rank=Rank.COMMANDER,
            age=30,
            specialization="Infiltration & Beer Supply",
            years_experience=5,
            is_active=True
        ),
        CrewMember(
            member_id="RES999",
            name="Alyx Vance",
            rank=Rank.OFFICER,
            age=24,
            specialization="Hacking & EMP Dog Command",
            years_experience=5,
            is_active=True
        )
    ]
    miss = SpaceMission(
        mission_id="M2026_COMBINE",
        mission_name="Operation: Citadel Collapse & Xen Portal Closure",
        destination="Border World Xen / Citadel Core",
        launch_date=datetime.now(),
        duration_days=3650,
        crew=mission_crew,
        mission_status='Ongoing',
        budget_millions=4320.30
    )
    print(f"Mission: {miss.mission_name}")
    print(f"ID: {miss.mission_id}")
    print(f"Destination: {miss.destination}")
    print(f"Duration: {miss.duration_days} days")
    print(f"Budget: ${miss.budget_millions}M")
    print(f"Crew size: {len(miss.crew)}")
    print("Crew members:")
    for p in mission_crew:
        print(f"- {p.name} ({p.rank.value}) - {p.specialization}")

    print("\nTest 1 (Missing Captain/Commander):")
    try:
        invalid_crew1 = [
            CrewMember(
                member_id="REB001",
                name="Lambda Rebel",
                rank=Rank.CADET,
                age=20,
                specialization="Crossbow Trainee",
                years_experience=1,
                is_active=True
            )
        ]
        SpaceMission(
            mission_id="M2026_HEADCRAB",
            mission_name="Ravenholm Recon (No Leader)",
            destination="Ravenholm",
            launch_date=datetime.now(),
            duration_days=10,
            crew=invalid_crew1,
            budget_millions=100.0
        )
    except ValidationError as e:
        for err in e.errors():
            print(err["msg"])

    print("\nTest 2 (Invalid Mission ID prefix):")
    try:
        SpaceMission(
            mission_id="APERTURE_01",
            mission_name="Borealis Recovery Mission",
            destination="Arctic Base",
            launch_date=datetime.now(),
            duration_days=100,
            crew=mission_crew,
            budget_millions=500.0
        )
    except ValidationError as e:
        for err in e.errors():
            print(err["msg"])

    print("\nTest 3 (Insufficient Experience for Long Mission):")
    try:
        low_exp_crew = [
            CrewMember(
                member_id="CAPT9",
                name="Promoted Recruit",
                rank=Rank.CAPTAIN,
                age=21,
                specialization="Pistol Specialist",
                years_experience=2,
                is_active=True
            ),
            CrewMember(
                member_id="OFF99",
                name="Resistance Novice",
                rank=Rank.OFFICER,
                age=19,
                specialization="Radio Operator",
                years_experience=1,
                is_active=True
            )
        ]
        SpaceMission(
            mission_id="M2026_XEN_DEEP",
            mission_name="Border World Teleportation Survey",
            destination="Xen Outskirts",
            launch_date=datetime.now(),
            duration_days=500,
            crew=low_exp_crew,
            budget_millions=1500.0
        )
    except ValidationError as e:
        for err in e.errors():
            print(err["msg"])

    print("\nTest 4 (Inactive Crew Member - G-Man Stasis):")
    try:
        inactive_crew = [
            CrewMember(
                member_id="GMAN01",
                name="Gordon Freeman (Stasis)",
                rank=Rank.CAPTAIN,
                age=27,
                specialization="Awaiting Employer Instructions",
                years_experience=10,
                is_active=False
            )
        ]
        SpaceMission(
            mission_id="M2026_STASIS",
            mission_name="City 17 Uprising",
            destination="City 17",
            launch_date=datetime.now(),
            duration_days=30,
            crew=inactive_crew,
            budget_millions=200.0
        )
    except ValidationError as e:
        for err in e.errors():
            print(err["msg"])


if __name__ == "__main__":
    main()
