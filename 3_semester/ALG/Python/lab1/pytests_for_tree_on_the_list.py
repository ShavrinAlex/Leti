from tree_on_the_list import create_tree, Node, Tree

def test1():
    for children, parent in enumerate([4, -1, 4, 1, 1]):
        if parent == -1:
            root = Node(children)
            tree = Tree(root)
    create_tree([4, -1, 4, 1, 1], root)

    assert tree.height(root) == 3

def test2():
    for children, parent in enumerate([-1, 0, 4, 0, 3]):
        if parent == -1:
            root = Node(children)
            tree = Tree(root)
    create_tree([-1, 0, 4, 0, 3], root)

    assert tree.height(root) == 4

def test3():
    for children, parent in enumerate([2, 2, -1, 0, 0, 3, 5, 6, 6, 8]):
        if parent == -1:
            root = Node(children)
            tree = Tree(root)
    create_tree([2, 2, -1, 0, 0, 3, 5, 6, 6, 8], root)

    assert tree.height(root) == 7

def test4():
    for children, parent in enumerate([4, 10, 3, 4, -1, 3, 2, 0, 5, 7, 7]):
        if parent == -1:
            root = Node(children)
            tree = Tree(root)
    create_tree([4, 10, 3, 4, -1, 3, 2, 0, 5, 7, 7], root)

    assert tree.height(root) == 5

def test4():
    for children, parent in enumerate([-1]):
        if parent == -1:
            root = Node(children)
            tree = Tree(root)
    create_tree([-1], root)

    assert tree.height(root) == 1
