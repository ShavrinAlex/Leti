#python
def MergeSorting(array):
    if len(array) <= 1:
        return array

    middle = len(array) // 2
    left, right = array[:middle], array[middle:]

    MergeSorting(left)
    MergeSorting(right)

    result_array = [0] * (len(left) + len(right))
    index_left = index_right = index = 0

    while index_left < len(left) and index_right < len(right):
        if left[index_left][1] <= right[index_right][1]:
            result_array[index] = left[index_left]
            index_left += 1
        else:
            result_array[index] = right[index_right]
            index_right += 1
        index += 1

    while index_left < len(left):
        result_array[index] = left[index_left]
        index_left += 1
        index += 1

    while index_right < len(right):
        result_array[index] = right[index_right]
        index_right += 1
        index += 1

    for i in range(len(array)):
        array[i] = result_array[i]

    for i in range(len(array)):
       print(array[i][0], end = ' ')
    print()

    return array

if __name__ == "__main__":
    n = int(input())
    sums_diagonals = []
    for matrix_number in range(n):
        sum_diagonal = 0
        matrix_size = int(input())
        for i in range(matrix_size):
            line = list(map(int, input().split(' ')))
            sum_diagonal += line[i]
        sums_diagonals.append((matrix_number, sum_diagonal))

    MergeSorting(sums_diagonals)
    for i in range(n):
        print(sums_diagonals[i][0], end = ' ')