#!/usr/bin/env python3

def input_temperature(temp_str: str) -> int:
    return int(temp_str)


def test_temperature() -> None:
    valid = "25"
    invalid = "abc"
    print("=== Garden Temperature ===\n")
    try:
        print(f"Input data is '{valid}'")
        print(f"Temperature is now: {input_temperature(valid)}°C\n")
        print(f"Input data is '{invalid}'")
        print(f"Output: {input_temperature(invalid)}\n")
    except ValueError as error:
        print(f"Caught input_temperature error: {error}")
    finally:
        print("All tests completed - program didn't crash!")


if __name__ == "__main__":
    test_temperature()
