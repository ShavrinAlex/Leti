from merge_sorting import MergeSorting

def test_from_emoevm():
    sums = [(0,32), (1, 11), (2, 3)]
    assert MergeSorting(sums) == [(2, 3), (1, 11), (0, 32)]

def test_without_matrix():
    sums = []
    assert MergeSorting(sums) == []

def test_with_one_matrix():
    sums = [(0, 1)]
    assert MergeSorting(sums) == [(0, 1)]

def test_with_equal_sum_of_diagonal():
    sums = [(0, 6), (1, 10), (2, 10)]
    assert MergeSorting(sums) == [(0, 6), (1, 10), (2, 10)]

def test_with_equal_sums_of_diagonals():
    sums = [(0, 5), (1, 5), (2, 5)]
    assert MergeSorting(sums) == [(0, 5), (1, 5), (2, 5)]

def test_with_zero_summ_diagonal():
    sums = [(0, 23), (1, 0), (2, 4)]
    assert MergeSorting(sums) == [(1, 0), (2, 4), (0, 23)]

def test_with_the_negative_sum_of_the_diagonal():
    sums = [(0, 5), (1, 34), (2, -34)]
    assert MergeSorting(sums) == [(2, -34), (0, 5), (1, 34)]

def test_with_the_negative_sums_of_the_diagonals():
    sums = [(0, -1), (1, -3), (2, -123)]
    assert MergeSorting(sums) == [(2, -123), (1, -3), (0, -1)]

