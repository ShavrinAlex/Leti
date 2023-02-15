#python

def heapify(arr, root, operations):
    min_index = root
    left_child_index = 2 * root + 1
    right_child_index = 2 * root + 2

    if left_child_index < len(arr) and arr[root] > arr[left_child_index]:
        min_index = left_child_index

    if right_child_index < len(arr) and arr[min_index] > arr[right_child_index]:
        min_index = right_child_index

    if min_index != root:
        operations[0] += 1
        operations[1] += f"{root} {min_index}\n"
        arr[root], arr[min_index] = arr[min_index], arr[root]
        heapify(arr, min_index, operations)


def heapSort(arr, n, operations):
    for i in range((n - 1)//2, -1, -1):
        heapify(arr, i, operations)

if __name__ == "__main__":
    n = int(input())
    operations = [0, ""]
    arr = list(map(int, input().split(' ')))
    heapSort(arr, n, operations)
    print(operations[0])
    print(operations[1], sep = '')