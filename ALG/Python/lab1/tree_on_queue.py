def create_children_list(parents_list, n):
    children_list = [[] for i in range(n+1)]
    for child in range(n):
        children_list[parents_list[child]].append(child)
    return children_list

def breadth_first_search(children_list, cur_level):
    queue = []
    height = 0
    while cur_level:
        queue = cur_level
        cur_level = []
        for child in queue:
            cur_level.extend(children_list[child])
        height += 1
    return height

if __name__ == "__main__":
    n = int(input())
    parents_list = list(map(int, input().split()))
    children_list = create_children_list(parents_list, n)
    print(breadth_first_search(children_list, children_list[-1]))
