#!/usr/bin/env python3

from __future__ import annotations
from enum import Enum
from typing import Optional
from datetime import datetime
from pydantic import BaseModel, ValidationError, Field, model_validator


class ContactType(str, Enum):
    RADIO = 'radio'
    VISUAL = 'visual'
    PHYSICAL = 'physical'
    TELEPATHIC = 'telepathic'


class AlienContact(BaseModel):
    contact_id: str = Field(min_length=5, max_length=15)
    timestamp: datetime
    location: str = Field(min_length=3, max_length=100)
    contact_type: ContactType
    signal_strength: float = Field(ge=0.0, le=10.0)
    duration_minutes: int = Field(ge=1, le=1440)
    witness_count: int = Field(ge=1, le=100)
    message_received: Optional[str] = Field(default=None, max_length=500)
    is_verified: bool = Field(default=True)

    @model_validator(mode='after')
    def validator(self) -> 'AlienContact':
        if not self.contact_id.startswith('AC'):
            raise ValueError("Contact ID must start with 'AC'")
        if self.contact_type == 'physical' and not self.is_verified:
            raise ValueError("Physical contact reports must be verified")
        if self.contact_type == 'telepathic' and self.witness_count < 3:
            raise ValueError("Telepathic contact requires at least 3"
                             " witnesses")
        if self.signal_strength > 7.0 and not self.message_received:
            raise ValueError("Strong signals (> 7.0) should "
                             "include received messages")
        return self


def main() -> None:
    print("Alien Contact Log Validation")
    print("======================================")
    print("Valid contact report: ")
    ac = AlienContact(
        contact_id="AC_2024_001",
        timestamp=datetime.now(),
        contact_type=ContactType.RADIO,
        location='Area 51, Nevada',
        signal_strength=8.5,
        duration_minutes=45,
        witness_count=5,
        message_received="Greetings from Zeta Reticuli"
    )
    print(f"ID: {ac.contact_id}")
    print(f"Date: {ac.timestamp}")
    print(f"Type: {ac.contact_type}")
    print(f"Location: {ac.location}")
    print(f"Signal: {ac.signal_strength}")
    print(f"Duration: {ac.duration_minutes}")
    print(f"Witnesses: {ac.witness_count}")
    print(f"Message: {ac.message_received}")
    print("")
    print("======================================")
    print("Expected validation error no. 1:")
    try:
        AlienContact(
            contact_id="BROSKI_2024_001",
            timestamp=datetime.now(),
            contact_type=ContactType.PHYSICAL,
            location='Area 51, Nevada',
            signal_strength=8.5,
            duration_minutes=45,
            witness_count=5,
            message_received="Greetings from Zeta Reticuli",
            is_verified=False,
        )
    except ValidationError as e:
        for error in e.errors():
            print(error["msg"] + '\n')
    print("Expected validation error no. 2:")
    try:
        AlienContact(
            contact_id="AC_2024_001",
            timestamp=datetime.now(),
            contact_type=ContactType.PHYSICAL,
            location='Area 51, Nevada',
            signal_strength=8.5,
            duration_minutes=45,
            witness_count=5,
            message_received="Greetings from Zeta Reticuli",
            is_verified=False,
        )
    except ValidationError as e:
        for error in e.errors():
            print(error["msg"] + '\n')
    print("Expected validation error no. 3:")
    try:
        AlienContact(
            contact_id="AC_2024_001",
            timestamp=datetime.now(),
            contact_type=ContactType.TELEPATHIC,
            location='Area 51, Nevada',
            signal_strength=8.5,
            duration_minutes=45,
            witness_count=1,
            message_received="Greetings from Zeta Reticuli",
            is_verified=False,
        )
    except ValidationError as e:
        for error in e.errors():
            print(error["msg"] + '\n')
    print("Expected validation error no. 4:")
    try:
        AlienContact(
            contact_id="AC_2024_001",
            timestamp=datetime.now(),
            contact_type=ContactType.TELEPATHIC,
            location='Area 51, Nevada',
            signal_strength=8.5,
            duration_minutes=45,
            witness_count=5,
            is_verified=True,
        )
    except ValidationError as e:
        for error in e.errors():
            print(error["msg"] + '\n')


if __name__ == "__main__":
    main()
