#!/usr/bin/env python3

from typing import Any, Protocol
from ex0.data_processor import (
    NumericProcessor,
    TextProcessor,
    LogProcessor,
)
from ex1.data_stream import DataStream as BaseDataStream


class ExportPlugin(Protocol):
    def process_output(self, data: list[tuple[int, str]]) -> None:
        pass


class CSVExportPlugin:
    def process_output(self, data: list[tuple[int, str]]) -> None:
        if not data:
            return
        values = [val for _, val in data]
        print("CSV Output:")
        print(",".join(values))


class JSONExportPlugin:
    def process_output(self, data: list[tuple[int, str]]) -> None:
        if not data:
            return
        pairs = [f'"item_{rank}": "{val}"' for rank, val in data]
        print("JSON Output:")
        print("{" + ", ".join(pairs) + "}")


class DataStream(BaseDataStream):
    def output_pipeline(self, nb: int, plugin: ExportPlugin) -> None:
        for proc in self._processors:
            extracted: list[tuple[int, str]] = []
            for _ in range(nb):
                if not proc._data:
                    break
                extracted.append(proc.output())
            if extracted:
                plugin.process_output(extracted)


def main() -> None:
    print("=== Code Nexus - Data Pipeline ===")
    print()
    print("Initialize Data Stream...")
    ds = DataStream()
    ds.print_processors_stats()
    print()

    print("Registering Processors")
    np = NumericProcessor()
    tp = TextProcessor()
    lp = LogProcessor()
    ds.register_processor(np)
    ds.register_processor(tp)
    ds.register_processor(lp)

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

    csv_plugin = CSVExportPlugin()
    print("Send 3 processed data from each processor to a CSV plugin:")
    ds.output_pipeline(3, csv_plugin)
    ds.print_processors_stats()
    print()

    batch2: list[Any] = [
        21,
        ['I love AI', 'LLMs are wonderful', 'Stay healthy'],
        [
            {'log_level': 'ERROR', 'log_message': '500 server crash'},
            {
                'log_level': 'NOTICE',
                'log_message': 'Certificate expires in 10 days',
            },
        ],
        [32, 42, 64, 84, 128, 168],
        'World hello',
    ]

    print(f"Send another batch of data: {batch2}")
    ds.process_stream(batch2)
    ds.print_processors_stats()
    print()

    json_plugin = JSONExportPlugin()
    print("Send 5 processed data from each processor to a JSON plugin:")
    ds.output_pipeline(5, json_plugin)
    ds.print_processors_stats()


if __name__ == "__main__":
    main()
