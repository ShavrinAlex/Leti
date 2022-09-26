class Node:
    def __init__(self, data):
        self.data = data
        self.children = []

    def get_data(self):
        return self.data

    def add_children(self, children):
        self.children.extend(children)

    def __str__(self):
        children_list = []
        if self.children:
            for child in self.children:
                children_list.append(child.get_data())
        return 'data: {}, childrens: {}\n'.format(self.data, children_list)

class Tree:
    def __init__(self, root):
        self.root = root

    def print_tree(self, node):
        print(node)
        for child in node.children:
            self.print_tree(child)

    def height(self, node):
        result_height = 1
        for child in node.children:
            result_height = max(result_height, 1 + self.height(child))
        return result_height

def create_tree(data, cur_parent):
    for children, parent in enumerate(data):
        if parent == cur_parent.get_data():
            child = Node(children)
            cur_parent.add_children([child])
            create_tree(data, child)

if __name__ == "__main__":
    n = int(input())
    data = list(map(int, input().split()))
    for children, parent in enumerate(data):
        if parent == -1:
            root = Node(children)
            tree = Tree(root)
    create_tree(data, root)

    #tree.print_tree(root)
    print(tree.height(root))
