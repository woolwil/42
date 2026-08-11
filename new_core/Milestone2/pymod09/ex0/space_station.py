#!/usr/bin/env python3

from pydantic import BaseModel, Field, ValidationError
from datetime import datetime
from typing import Optional


class SpaceStation(BaseModel):
    station_id: str = Field(min_length=3, max_length=10)
    name: str = Field(min_length=1, max_length=50)
    crew_size: int = Field(ge=1, le=20)
    power_level: float = Field(ge=0.0, le=100.0)
    oxygen_level: float = Field(ge=0.0, le=100.0)
    last_maintenance: datetime
    is_operational: bool = Field(default=True)
    notes: Optional[str] = Field(default=None, max_length=200)


def main() -> None:
    iss = SpaceStation(
        station_id="IS001",
        name="International Space Station",
        crew_size=6,
        power_level=85.5,
        oxygen_level=92.3,
        last_maintenance=datetime.now(),
        is_operational=True,
    )
    print("Space Station Data Validation")
    print("========================================")
    print("Valid station created:")
    print(f"ID: {iss.station_id}")
    print(f"Name: {iss.name}")
    print(f"Crew: {iss.crew_size} people")
    print(f"Power: {iss.power_level}%")
    print(f"Oxygen: {iss.oxygen_level}%")
    print("Status: " + "Operational" if iss.is_operational else "Inoperative")
    print("")
    print("========================================")
    print("Expected validation error:")

    try:
        SpaceStation(
            station_id="ISS00X",
            name="Invalid Station",
            crew_size=25,
            power_level=85.5,
            oxygen_level=92.3,
            last_maintenance=datetime.now()
        )
    except ValidationError as e:
        for error in e.errors():
            print(error["msg"])


if __name__ == "__main__":
    main()
