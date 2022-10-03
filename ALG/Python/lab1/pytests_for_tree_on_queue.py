from tree_on_queue import create_children_list, breadth_first_search

def test1():
    children_list = create_children_list([4, -1, 4, 1, 1], 5)
    assert breadth_first_search(children_list, children_list[-1]) == 3

def test2():
    children_list = create_children_list([-1, 0, 4, 0, 3], 5)
    assert breadth_first_search(children_list, children_list[-1]) == 4

def test3():
    children_list = create_children_list([2, 2, -1, 0, 0, 3, 5, 6, 6, 8], 10)
    assert breadth_first_search(children_list, children_list[-1]) == 7

def test4():
    children_list = create_children_list([4, 10, 3, 4, -1, 3, 2, 0, 5, 7, 7], 11)
    assert breadth_first_search(children_list, children_list[-1]) == 5

def test5():
    children_list = create_children_list([-1], 1)
    assert breadth_first_search(children_list, children_list[-1]) == 1

def test6():
    children_list = create_children_list([], 0)
    assert breadth_first_search(children_list, children_list[-1]) == 0
