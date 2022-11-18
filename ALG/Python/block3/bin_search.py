def solve(L, x):
    low_index = 0
    hight_index = len(L) - 1
    mid = 0
    eps = 0.00001
    result = -1

    while low_index <= hight_index and result == -1:
        mid = (low_index + hight_index)//2
        if (abs(L[mid] - x) <= eps):
            result = mid
        else:
            if L[mid] - x > -eps:
                hight_index = mid - 1
            else:
                low_index = mid + 1

    return result;