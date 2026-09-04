def inter(s1: str, s2: str) -> str:
    set_s2 = set(s2)
    seen = set()
    result = []

    for c in s1:
        if c in set_s2 and c not in seen:
            seen.add(c)
            result.append(c)
    return "".join(result)


def main() -> None:
    print(inter("hello", "world"))
    print(inter("banana", "band"))
    print(inter("abcabc", "bc"))
    print(inter('padinton', 'paqefwtdjnp'))


if __name__ == "__main__":
    main()
