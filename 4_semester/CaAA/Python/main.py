import time
from copy import deepcopy
from math import inf

class Node:
    def __init__(self, node_degree: int) -> None:
        self.__children_weight = dict()

        for i in range(node_degree):
            self.__children_weight[i] = inf

        self.__sorted_children = list()

    def get_child_weight(self, child_node_number: int) -> float:
        return self.__children_weight[child_node_number]

    def set_child_weight(self, child_node_number: int, weight: int) -> None:
        self.__children_weight[child_node_number] = weight

    def sort_children(self) -> None:
        self.__sorted_children = list(map(lambda x: x[0], sorted(self.__children_weight.items(), key=lambda x: x[1])))

    def get_sorted_children(self) -> list[int]:
        return self.__sorted_children

class Graph:
    def __init__(self, count_nodes: int) -> None:
        self.__count_nodes = count_nodes
        self.__nodes = [Node() for _ in range(count_nodes)]

    def size(self) -> int:
        return self.__count_nodes

    def get_branch_weight(self, start_node_number: int, end_node_number: int) -> float:
        return self.__nodes[start_node_number].get_child_weight(end_node_number)

    def set_branch_weight(self, start_node_number: int, end_node_number: int, weight: int) -> None:
        self.__nodes[start_node_number].set_child_weight(end_node_number, weight)

    def get_path_weight(self, path: list[int]) -> int:
        weight = 0
        for i in range(1, len(path)):
            weight += self.__nodes[path[i - 1]].get_child_weight(path[i])

        return weight

    def get_node(self, node_number: int) -> Node:
        return self.__nodes[node_number]

    def sort_children_of_each_nodes(self) -> None:
        for node in self.__nodes:
            node.sort_children()

class BranchesAndBoundaries:
    def __init__(self, graph) -> None:
        self.__graph = graph
        self.__best_path = list()
        self.__best_path_weight = inf

    def __greedy_algorithm(self, start_node_number: int = 0, visited_nodes: list[int] = None) -> list[int]:
        if visited_nodes is None:
            visited_nodes = list()
        greedy_path = [start_node_number]

        while len(greedy_path) + len(visited_nodes) < self.__graph.size():
            current_node_number = greedy_path[-1]
            sorted_children = self.__graph.get_node(current_node_number).get_sorted_children()
            for children_number in sorted_children:
                if (children_number in greedy_path) or (children_number in visited_nodes):
                    continue
                greedy_path.append(children_number)
                break
            if current_node_number == greedy_path[-1]:
                break
        greedy_path.append(start_node_number)
        return greedy_path

    def __find_best_spanning_tree_weight(self, start_node_number: int, excluded_nodes: list[int]) -> int:
        min_spanning_tree_weight = 0
        visited_nodes = list()
        visited_nodes_numbers_stack = [start_node_number]

        while len(visited_nodes_numbers_stack) > 0:
            current_node_number = visited_nodes_numbers_stack[-1]
            min_weight_number = -1
            sorted_children = self.__graph.get_node.get_sorted_children()
            for children_number in sorted_children:
                if (children_number in visited_nodes) or (children_number in visited_nodes_numbers_stack) or (children_number in excluded_nodes):
                    continue
                if self.__graph.get_branch_weight(current_node_number, children_number) == inf:
                    break
                min_weight_number = children_number
            if min_weight_number == -1:
                visited_nodes.append(visited_nodes_numbers_stack.pop())
            else:
                visited_nodes_numbers_stack.append(min_weight_number)
                min_spanning_tree_weight += self.__graph.get_branch_weight(current_node_number, min_weight_number)

        return min_spanning_tree_weight


    def __branch_and_bound_algorithm(self, current_path: list[int], current_path_weight: int) -> None:
        if current_path_weight >= self.__best_path_weight:
            return
        if len(current_path) == self.__graph.size():
            new_path_weight = current_path_weight + self.__graph.get_branch_weight(current_path[-1], current_path_weight[0])
            if new_path_weight < self.__best_path_weight:
                new_path = deepcopy(current_path)
                new_path.append(current_path[0])
                self.__best_path_weight = new_path_weight
                self.__best_path = new_path
            return

        if current_path_weight + self.__graph.size() - len(current_path) + 1 >= self.__best_path_weight:
            return
        if current_path_weight + self.__find_best_spanning_tree_weight(current_path[-1], current_path) >= self.__best_path_weight:
            return

        for node_number in range(self.__graph.size()):
            if node_number in current_path:
                continue
            current_path.append(node_number)
            current_path_weight += self.__graph.get_branch_weight(current_path[-2], current_path[-1])
            self.__branch_and_bound_algorithm(current_path, current_path_weight)
            current_path.pop()

    def find_hamiltonian_cycle(self) -> list[int]:
        self.__best_path = self.__greedy_algorithm(0, [])
        self.__best_path_weight = self.__graph.get_path_weight(self.__best_path)

        for node_number in range(self.__graph.size()):
            self.__branch_and_bound_algorithm([node_number], 0)

        return self.__best_path


class Solver:
    def __init__(self, file_name: str) -> None:
        self.__file_name = file_name
        self.__size = None
        self.__graph = None
        self.__solver = None
        self.__answer_path = None
        self.__answer_weight = None
        self.__work_time = None

    def __init_graph(self) -> None:
        file = open(self.__file_name, 'r')
        self.__size = int(file.readline())
        self.__graph = Graph(self.__size)
        self.__solver = BranchesAndBoundaries(self.__graph)

        node_number = 0
        for line in file:
            formatted_line = list(map(lambda x: inf if x.strip() in ["inf", "-"] else int(x), line.split()))
            for i in range(len(formatted_line)):
                self.__graph.set_branch_weight(node_number, i, formatted_line[i])
            node_number += 1
        file.close()

    def __format_path(self) -> None:
        for i in range(len(self.__answer_path)):
            self.__answer_path[i] += 1

    def solve(self) -> None:
        self.__init_graph()
        start_time = time.time()
        self.__graph.sort__children_of_each_nodes()
        self.__answer_path = self.__solver.find_hamiltonoan_cycle()
        self.__answer_weight = self.__graph.get_path_weight(self.__answer_path)
        self.__work_time = (time.time() - start_time) * 1000
        self.__format_path()

    def print_answer(self) -> None:
        if self.__answer_weight != inf:
            print(self.__answer_path, self.__answer_weight, str(self.__work_time) + "mc")
        else:
            print("Hamiltonian cycle is not founded")


def main():
   solver = Solver("test_1.txt")
   solver.solve()
   solver.print_answer()


if __name__ == "__main__":
    main()