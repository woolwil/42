#!/usr/bin/env python 3

import random
import typing

players = ["alice", "bob", "charlie", "dylan"]
actions = [
    "run", "eat", "sleep",
    "grab", "move", "swim",
    "use", "climb", "release"
    ]


def gen_event() -> typing.Generator[tuple[str, str], None, None]:
    while True:
        player = random.choice(players)
        action = random.choice(actions)
        yield (player, action)


def consume_event(events_list: list[tuple[str, str]]) -> typing.Generator[
        tuple[str, str], None, None]:
    while len(events_list) > 0:
        index = random.randint(0, len(events_list) - 1)
        event = events_list[index]
        del events_list[index]
        yield event


def main():
    print("=== Game Data Stream Processor ===")
    event_stream = gen_event()

    for iter in range(1000):
        name, action = next(event_stream)
        print(f"Event {iter}: Player {name} did action {action}")

    event_list = [next(event_stream) for _ in range(10)]
    print(f"Built list of 10 events: {event_list}")

    for event in consume_event(event_list):
        print(f"Got event from list: {event}")
        print(f"Remains in list: {event_list}")


if __name__ == "__main__":
    main()
