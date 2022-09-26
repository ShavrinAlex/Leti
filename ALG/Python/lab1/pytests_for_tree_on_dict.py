from tree_on_dict import create_tree, height

def test1():
    tree = create_tree([4, -1, 4, 1, 1])
    assert height(tree, -1) == 3

def test2():

    tree = create_tree([-1, 0, 4, 0, 3])
    assert height(tree, -1) == 4

def test3():
    tree = create_tree([2, 2, -1, 0, 0, 3, 5, 6, 6, 8])
    assert height(tree, -1) == 7

def test4():
    tree = create_tree([4, 10, 3, 4, -1, 3, 2, 0, 5, 7, 7])
    assert height(tree, -1) == 5

def test5():
    tree = create_tree([-1])
    assert height(tree, -1) == 1
