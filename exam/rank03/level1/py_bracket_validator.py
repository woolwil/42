def bracket_validator(s: str) -> bool:
    stack = []
    matching_bracket = {
        ')': '(',
        ']': '[',
        '}': '{', 
    }
    for c in s:
        if c == '(' or c == '[' or c == '{':
            stack.append(c)
        elif c == ')' or c == '}' or c == ']':
            if not stack:
                return False
            else:
                top_bracket = stack.pop()
                if top_bracket != matching_bracket[c]:
                    return False
    return len(stack) == 0


def main() -> None:
    print(bracket_validator("()[]{}"))
    print(bracket_validator("([{}])"))
    print(bracket_validator("([)])"))
    print(bracket_validator("((("))
    print(bracket_validator(")"))

if __name__ == "__main__":
    main()
