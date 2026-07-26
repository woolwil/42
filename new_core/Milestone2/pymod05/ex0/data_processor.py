#!/usr/bin/env python3

from typing import Any
import abc


class DataProcessor(abc.ABC):
    def __init__(self) -> None:
        self._data: list[tuple[int, str]] = []
        self._rank: int = 0

    @abc.abstractmethod
    def validate(self, data: Any) -> bool:
        pass

    @abc.abstractmethod
    def ingest(self, data: Any) -> None:
        pass

    def output(self) -> tuple[int, str]:
        if not self._data:
            raise IndexError("No data available to output")
        else:
            return self._data.pop(0)


class NumericProcessor(DataProcessor):
    def validate(self, data: Any) -> bool:
        if isinstance(data, (int, float)) and not isinstance(data, bool):
            return True
        if isinstance(data, list):
            return all(
                isinstance(x, (int, float)) and not isinstance(x, bool)
                for x in data
            )
        else:
            return False

    def ingest(self, data: int | float | list[int | float]) -> None:
        if not self.validate(data):
            raise ValueError("Improper numeric data")
        if isinstance(data, list):
            for item in data:
                self._data.append((self._rank, str(item)))
                self._rank += 1
        else:
            self._data.append((self._rank, str(data)))
            self._rank += 1


class TextProcessor(DataProcessor):
    def validate(self, data: Any) -> bool:
        if isinstance(data, str):
            return True
        if isinstance(data, list):
            return all(isinstance(x, str) for x in data)
        return False

    def ingest(self, data: str | list[str]) -> None:
        if not self.validate(data):
            raise ValueError("Improper text data")
        if isinstance(data, list):
            for item in data:
                self._data.append((self._rank, item))
                self._rank += 1
        else:
            self._data.append((self._rank, data))
            self._rank += 1


class LogProcessor(DataProcessor):
    def validate(self, data: Any) -> bool:
        if isinstance(data, dict):
            return all(
                isinstance(k, str) and isinstance(v, str)
                for k, v in data.items()
            )
        if isinstance(data, list):
            return all(self.validate(x) for x in data)
        return False

    def ingest(self, data: dict[str, str] | list[dict[str, str]]) -> None:
        if not self.validate(data):
            raise ValueError("Improper log data")
        items = data if isinstance(data, list) else [data]
        for item in items:
            if 'log_level' in item and 'log_message' in item:
                log_str = f"{item['log_level']}: {item['log_message']}"
            else:
                log_str = ", ".join(f"{k}: {v}" for k, v in item.items())
            self._data.append((self._rank, log_str))
            self._rank += 1


def main() -> None:
    print("=== Code Nexus - Data Processor ===")
    print()
    print("Testing Numeric Processor...")
    np = NumericProcessor()
    print(f"Trying to validate input '42': {np.validate(42)}")
    print(f"Trying to validate input 'Hello': {np.validate('Hello')}")
    print("Test invalid ingestion of string 'foo' without prior validation:")
    try:
        np.ingest("foo")  # type: ignore
    except ValueError as e:
        print(f"Got exception: {e}")
    print("Processing data: [1, 2, 3, 4, 5]")
    np.ingest([1, 2, 3, 4, 5])
    print("Extracting 3 values...")
    for _ in range(3):
        rank, val = np.output()
        print(f"Numeric value {rank}: {val}")
    print()

    print("Testing Text Processor...")
    tp = TextProcessor()
    print(f"Trying to validate input '42': {tp.validate(42)}")
    print("Processing data: ['Hello', 'Nexus', 'World']")
    tp.ingest(['Hello', 'Nexus', 'World'])
    print("Extracting 1 value...")
    rank, val = tp.output()
    print(f"Text value {rank}: {val}")
    print()

    print("Testing Log Processor...")
    lp = LogProcessor()
    print(f"Trying to validate input 'Hello': {lp.validate('Hello')}")
    log_data = [
        {'log_level': 'NOTICE', 'log_message': 'Connection to server'},
        {'log_level': 'ERROR', 'log_message': 'Unauthorized access!!'}
    ]
    print(f"Processing data: {log_data}")
    lp.ingest(log_data)
    print("Extracting 2 values...")
    for _ in range(2):
        rank, val = lp.output()
        print(f"Log entry {rank}: {val}")


if __name__ == "__main__":
    main()
