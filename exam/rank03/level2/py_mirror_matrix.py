def mirror_matrix(matrix: list[list[int]]) -> list[list[int]]:
    return [row[::-1] for row in matrix]

def main() -> None:
    m1 = [[1, 2, 3],[4, 5, 6]]
    m2 = [[1,2],[3,4],[5,6]]
    m3 = [[-1,-2],[-3,-4]]
    m4 = [[1,2,3,4]]
    print(mirror_matrix(m1))
    print(mirror_matrix(m2))
    print(mirror_matrix(m3))
    print(mirror_matrix(m4))


if __name__ == "__main__":
    main()
