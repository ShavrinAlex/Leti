def InOrder(tree, elem, arr):
    if tree[elem][1] == -1 and tree[elem][2] == -1:
        arr.append(tree[elem][0])
        return arr

    if tree[elem][1] != -1:
        arr = InOrder(tree, tree[elem][1], arr)

    arr.append(tree[elem][0])

    if tree[elem][2] != -1:
        arr = InOrder(tree, tree[elem][2], arr)

    return arr

def PreOrder(tree, elem, arr):
    arr.append(tree[elem][0])

    if tree[elem][1] == -1 and tree[elem][2] == -1:
        return arr

    if tree[elem][1] != -1:
        arr = InOrder(tree, tree[elem][1], arr)

    if tree[elem][2] != -1:
        arr = InOrder(tree, tree[elem][2], arr)

    return arr


def PostOrder(tree, elem, arr):
    if tree[elem][1] == -1 and tree[elem][2] == -1:
        arr.append(tree[elem][0])
        return arr

    if tree[elem][1] != -1:
        arr = InOrder(tree, tree[elem][1], arr)

    if tree[elem][2] != -1:
        arr = InOrder(tree, tree[elem][2], arr)

    arr.append(tree[elem][0])

    return arr


if __name__ == "__main__":
    n = int(input())
    tree = [None] * n
    for i in range(n):
        tree[i] = list(map(int, input().split(' ')))

    in_order = InOrder(tree, 0, [])
    pre_order = PreOrder(tree, 0, [])
    post_order = PostOrder(tree, 0, [])

    print(in_order)
    print(pre_order)
    print(post_order)
