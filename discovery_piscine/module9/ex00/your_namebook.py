#!/usr/bin/env python3


def array_of_names(dik):
    full_name = []
    for first, last in dik.items():
        cap_first = first.capitalize()
        cap_last = last.capitalize()
        full_name.append(f"{cap_first} {cap_last}")
    return (full_name)


def main():
    persons = {
        "jean": "valjean",
        "grace": "hopper",
        "xavier": "niel",
        "fifi": "brindacier"
        }
    print(array_of_names(persons))


if __name__ == "__main__":
    main()
