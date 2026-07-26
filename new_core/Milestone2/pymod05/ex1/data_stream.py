#!/usr/bin/env python3

from typing import Any
from ex0.data_processor import (
    DataProcessor,
    NumericProcessor,
    TextProcessor,
    LogProcessor,
)


class DataStream:
    def __init__(self) -> None:
        self._processors: list[DataProcessor] = []

    def register_processor(self, proc: DataProcessor) -> None:
        self._processors.append(proc)

    def process_stream(self, stream: list[Any]) -> None:
        for element in stream:
            handled = False
            for proc in self._processors:
                if proc.validate(element):
                    proc.ingest(element)
                    handled = True
                    break
            if not handled:
                print(
                    f"DataStream error - Can't process element in stream: "
                    f"{element}"
                )

    def print_processors_stats(self) -> None:
        print("== DataStream statistics ==")
        if not self._processors:
            print("No processor found, no data")
            return
        for proc in self._processors:
            name = proc.__class__.__name__
            if name == "NumericProcessor":
                label = "Numeric Processor"
            elif name == "TextProcessor":
                label = "Text Processor"
            elif name == "LogProcessor":
                label = "Log Processor"
            else:
                label = name
            print(
                f"{label}: total {proc._rank} items processed, "
                f"remaining {len(proc._data)} on processor"
            )


def main() -> None:
    print("=== Code Nexus - Data Stream ===")
    print()
    print("Initialize Data Stream...")
    ds = DataStream()
    ds.print_processors_stats()
    print()

    print("Registering Numeric Processor")
    np = NumericProcessor()
    ds.register_processor(np)
    print()

    batch1: list[Any] = [
        'Hello world',
        [3.14, -1, 2.71],
        [
            {
                'log_level': 'WARNING',
                'log_message': 'Telnet access! Use ssh instead',
            },
            {'log_level': 'INFO', 'log_message': 'User wil is connected'},
        ],
        42,
        ['Hi', 'five'],
    ]

    print(f"Send first batch of data on stream: {batch1}")
    ds.process_stream(batch1)
    ds.print_processors_stats()
    print()

    print("Registering other data processors")
    tp = TextProcessor()
    lp = LogProcessor()
    ds.register_processor(tp)
    ds.register_processor(lp)

    print("Send the same batch again")
    ds.process_stream(batch1)
    ds.print_processors_stats()
    print()

    print(
        "Consume some elements from the data processors: Numeric 3, "
        "Text 2, Log 1"
    )
    for _ in range(3):
        np.output()
    for _ in range(2):
        tp.output()
    for _ in range(1):
        lp.output()

    ds.print_processors_stats()


if __name__ == "__main__":
    main()
