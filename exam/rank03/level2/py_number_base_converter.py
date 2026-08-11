def number_base_converter(number: str, from_base: int, to_base: int) -> str:
    if number == "0" or not number:
        return "0"

    # STEP 1: Convert the input string into a Base-10 Integer
    # Python's built-in int(str, base) handles bases 2 to 36 automatically!
    decimal_val = int(number, from_base)

    if to_base == 10:
        return str(decimal_val)

    # STEP 2: Convert the Base-10 Integer into the target `to_base`
    digits = "0123456789ABCDEF"
    result = []

    while decimal_val > 0:
        remainder = decimal_val % to_base
        result.append(digits[remainder])  # Pick the digit for this remainder
        decimal_val //= to_base           # Divide by target base

    # Since remainders are collected backwards, reverse the list at the end
    return "".join(reversed(result))

def main() -> None:
    print(number_base_converter("42", 10, 2))      # Output: "101010"
    print(number_base_converter("101010", 2, 10))  # Output: "42"
    print(number_base_converter("42", 10, 16))     # Output: "2A"
    print(number_base_converter("2A", 16, 10))     # Output: "42"
    print(number_base_converter("FF", 16, 2))      # Output: "11111111"
    print(number_base_converter("0", 10, 2))       # Output: "0"


if __name__ == "__main__":
    main()