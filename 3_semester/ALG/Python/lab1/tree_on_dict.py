def create_tree(data):
    tree = {i: [] for i in data}
    for index, elem in enumerate(data):
        tree[elem].append(index)
    print(tree)
    return tree

def height(tree, cur_node):
    cur_height = 1
    for child in tree[cur_node]:
        if child in tree.keys():
            cur_height = max(cur_height, 1 + height(tree, child))
    return cur_height


if __name__ == "__main__":
    #n = int(input())
    data = list(map(int, input().split()))
    if data == []:
        print(0)
    else:
        tree = create_tree(data)
        print(height(tree, -1))