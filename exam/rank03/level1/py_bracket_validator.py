def bracket_validator(s: str) -> bool:
    stack = []
    pairs = {
            ')': '(',
            ']': '[',
            '}': '{'
        }

    for c in s:
        if c in pairs.values():
            stack.append(c)
        elif c in pairs and (not stack or stack.pop() != pairs[c]):
            return False
    return not stack


def main() -> None:
    # true
    print(bracket_validator("hello(world)"))
    print(bracket_validator("()[]{}"))
    print(bracket_validator("([{}])"))
    # false
    print(bracket_validator("([)])"))
    print(bracket_validator("((("))
    print(bracket_validator(")"))
    print(bracket_validator("((())"))

if __name__ == "__main__":
    main()
