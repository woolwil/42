def number_base_converter(number: str, from_base: int, to_base: int) -> str:
    digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    if not (2 <= from_base <= 36 and 2 <= to_base <= 36):
        return "ERROR"
    if not number or any(c.upper() not in digits[:from_base] for c in number):
        return "ERROR"
    n = int(number, from_base)
    if n == 0:
        return "0"
    res = ""
    while n > 0:
        res = digits[n % to_base] + res  # Prepend digit directly
        n //= to_base
    return res


def main() -> None:
    print(number_base_converter("42", 10, 2))      # Output: "101010"
    print(number_base_converter("101010", 2, 10))  # Output: "42"
    print(number_base_converter("42", 10, 16))     # Output: "2A"
    print(number_base_converter("2A", 16, 10))     # Output: "42"
    print(number_base_converter("FF", 16, 2))      # Output: "11111111"
    print(number_base_converter("0", 10, 2))       # Output: "0"


if __name__ == "__main__":
    main()
