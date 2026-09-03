def inter(s1: str, s2: str) -> str:
    result = []
    for c in s1:
        if c in s2 and c not in result:
            result.append(c)
    return "".join(result)

def main() -> None:
    print(inter('padinton', 'paqefwtdjnp'))
    print(inter("banana", "band"))
        

if __name__ == "__main__":
    main()
