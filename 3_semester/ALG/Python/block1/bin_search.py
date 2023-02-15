def bin_search(arr, elem, start, end):
    if start <= end:
        mid = (start + end) // 2
        if arr[mid] == elem:
            return mid
        if arr[mid] > elem:
            return bin_search(arr, elem, start, mid - 1)
        if arr[mid] < elem:
            return bin_search(arr, elem, mid + 1, end)
    else:
        return -1


def tests():
    assert bin_search(lst, 5, 0, len(lst)) == 4
    assert bin_search(lst, 3, 0, len(lst)) == 2
    assert bin_search(lst, 7, 0, len(lst)) == 6


lst = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
if __name__ == "__main__":
    tests()
