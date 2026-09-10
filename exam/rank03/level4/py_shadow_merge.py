# def shadow_merge(list1: list[int], list2: list[int]) -> list[int]:
#     """
#     Merges two sorted lists into a single sorted list in O(n + m) time.
#     """
#     merged: list[int] = []
#     i = 0
#     j = 0
#     len1 = len(list1)
#     len2 = len(list2)

#     while i < len1 and j < len2:
#         if list1[i] <= list2[j]:
#             merged.append(list1[i])
#             i += 1
#         else:
#             merged.append(list2[j])
#             j += 1

#     merged.extend(list1[i:])
#     merged.extend(list2[j:])
#     return merged

def shadow_merge(list1: list[int], list2: list[int]) -> list[int]:
    return sorted(list1 + list2)


def main() -> None:
    print(shadow_merge([1, 3, 5], [2, 4, 6]))          # [1, 2, 3, 4, 5, 6]
    print(shadow_merge([1, 2, 3], [4, 5, 6]))          # [1, 2, 3, 4, 5, 6]
    print(shadow_merge([], [1, 2]))                    # [1, 2]
    print(shadow_merge([1, 2], []))                    # [1, 2]
    print(shadow_merge([1, 3, 3, 7], [2, 3, 5]))       # [1, 2, 3, 3, 3, 5, 7]


if __name__ == "__main__":
    main()

