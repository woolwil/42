def twist_sequence(arr: list[int], k: int) -> list[int]:
    """
    Rotates an array to the right by k positions.
    The last k elements move to the front.
    """
    if not arr:
        return []
    k = k % len(arr)
    if k == 0:
        return arr[:]
    return arr[-k:] + arr[:-k]


def main() -> None:
    print(twist_sequence([1, 2, 3, 4, 5], 2))  # [4, 5, 1, 2, 3]
    print(twist_sequence([1, 2, 3, 4, 5], 0))  # [1, 2, 3, 4, 5]
    print(twist_sequence([1, 2, 3, 4, 5], 5))  # [1, 2, 3, 4, 5]
    print(twist_sequence([1, 2, 3, 4, 5], 7))  # [4, 5, 1, 2, 3]
    print(twist_sequence([], 3))               # []
    print(twist_sequence([42], 10))            # [42]


if __name__ == "__main__":
    main()
