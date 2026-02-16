#!/usr/bin/env python3


# def find_the_redheads(dik):
#     ppl = []
#     for name, hair_color in dik.items():
#         if hair_color == "red":
#             ppl.append(name)
#     return ppl

def find_the_redheads(dik):
    return list(filter(lambda name: dik[name] == "red", dik.keys()))


def main():
    dupont_family = {
        "florian": "red",
        "marie": "blond",
        "virginie": "brunette",
        "david": "red",
        "franck": "red"
        }
    print(find_the_redheads(dupont_family))


if __name__ == "__main__":
    main()
