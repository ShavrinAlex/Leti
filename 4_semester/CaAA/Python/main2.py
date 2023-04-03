from time import time
from copy import deepcopy
from math import inf


class Node:
    """
    Graph node class that stores the weights of branches to neighboring nodes and a sorted list
    of numbers of child nodes by the cost of the path to them
    """
    def __init__(self, node_degree: int) -> None:
        """
        This method initializes the initial parameters of the graph node
        :param node_degree: maximum number of child nodes (number of outgoing branches)
        """

        self.__children_weight = dict()
        for node_number in range(node_degree):
            self.__children_weight[node_number] = inf
        self.__children = list()

    def __getitem__(self, child_node_number: int) -> float:
        """
        This method returns the weight of the branch to the passed child node
        :param child_node_number: the number of the child node to which you need to get the cost of the path
        :return: weight of the branch to the passed child node
        """

        return self.__children_weight[child_node_number]

    def __setitem__(self, child_node_number: int, weight: int) -> None:
        """
        This method sets the weight of the arc to the passed child node
        :param child_node_number: the number of the child node to which you need to set the cost of the path
        :param weight:  weight of the branch to the passed child node
        :return: None
        """

        self.__children_weight[child_node_number] = weight

    def sort_children(self) -> None:
        """
        This method sorts the list of child node numbers
        :return: None
        """

        self.__children = list(map(lambda x: x[0], sorted(self.__children_weight.items(), key=lambda x: x[1])))

    def get_children(self) -> list[int]:
        """
        This method returns a sorted list of child node numbers
        :return: sorted list of child node numbers
        """

        return self.__children


class Graph:
    """A graph class that stores graph nodes and organizes work with itself"""

    def __init__(self, count_nodes: int) -> None:
        """
        This method initializes the initial parameters of the graph
        :param count_nodes: count of nodes in the graph
        """

        self.__count_nodes = count_nodes
        self.__nodes = [Node(self.__count_nodes) for _ in range(count_nodes)]

    def get_branch_weight(self, start_node_number: int, end_node_number: int) -> float:
        """
        This method returns the weight of the branch between the passed nodes
        :param start_node_number: the number of the node from which the branch exits
        :param end_node_number: the number of the node that the branch belongs to
        :return: the weight of the branch between the start and end nodes
        """

        return self.__nodes[start_node_number][end_node_number]

    def set_branch_weight(self, start_node_number: int, end_node_number: int, weight: int) -> None:
        """
        This method sets the weight of the branch between the passed nodes
        :param start_node_number: the number of the node from which the branch exits
        :param end_node_number: the number of the node that the branch belongs to
        :param weight: the weight of the branch between the start and end nodes
        :return: None
        """

        self.__nodes[start_node_number][end_node_number] = weight

    def get_path_weight(self, path: list[int]) -> int:
        """
        This method calculates the weight of the transmitted path
        :param path: list of node numbers
        :return: the weight of the transmitted path
        """

        path_weight = 0
        for i in range(1, len(path)):
            path_weight += self.__nodes[path[i - 1]][path[i]]
        return path_weight

    def sort(self) -> None:
        """
        This method sorts the lists of child nodes in all nodes of the graph
        :return: None
        """

        for node in self.__nodes:
            node.sort_children()

    def __len__(self) -> int:
        """
        This method returns the number of nodes in the graph
        :return: count of nodes in the graph
        """

        return self.__count_nodes

    def __getitem__(self, node_number) -> Node:
        """
        This method returns a node object with the passed node number
        :param node_number: the number of the node to get
        :return: a node object with the passed node number
        """

        return self.__nodes[node_number]


class Solver:
    """Solver - a class solving the problem of finding a Hamiltonian path"""
    def __init__(self, graph) -> None:
        """
        This method initializes the initial parameters of the Solver
        :param graph: node graph
        """

        self.__graph = graph
        self.__start_node = 0
        self.__best_hamiltonian_cycle = list()
        self.__best_hamiltonian_cycle_weight = inf

    def __lower_bound(self, start_node_number: int, current_path: list[int]) -> int:
        min_spanning_tree_weight = 0
        visited_nodes_numbers = []
        visited_nodes_numbers_stack = [start_node_number]

        while len(visited_nodes_numbers_stack) > 0:
            best_node_index = -1
            min_weight = inf
            current_node_number = visited_nodes_numbers_stack[-1]

            for child_node_number in self.__graph[current_node_number].get_children():
                child_weight = self.__graph.get_branch_weight(current_node_number, child_node_number)

                if (child_node_number not in current_path) and (child_weight < min_weight)\
                        and (child_node_number not in visited_nodes_numbers)\
                        and (child_node_number not in visited_nodes_numbers_stack):
                    min_weight = child_weight
                    best_node_index = child_node_number
                    break

            if best_node_index == -1:
                visited_nodes_numbers.append(visited_nodes_numbers_stack.pop())
            else:
                visited_nodes_numbers_stack.append(best_node_index)
                min_spanning_tree_weight += min_weight

        return min_spanning_tree_weight

    def __find_next_node(self, current_node_number, current_path, visited_branches: list[list[bool]]) -> int:
        current_node = self.__graph[current_node_number]
        min_weight = inf
        best_node_number = -1

        for child_node_number in current_node.get_children():
            if (current_node[child_node_number] < min_weight) and (child_node_number not in current_path) and (child_node_number != self.__start_node or len(current_path) == len(self.__graph) - 1):
                if not visited_branches[current_node_number][child_node_number]:
                    min_weight = current_node[child_node_number]
                    best_node_number = child_node_number

        if best_node_number != -1:
            visited_branches[current_node_number][best_node_number] = True
        return best_node_number

    """
    def __greedy_algorithm(self, start_node_number: int, visited_nodes: list[int]) -> list[int]:
        
        This method finds a possible minimal Hamiltonian cycle using a greedy algorithm
        :param start_node_number:
        :param visited_nodes:
        :return:
        

        greedy_hamiltonian_cycle = [start_node_number]
        while len(greedy_hamiltonian_cycle) + len(visited_nodes) < len(self.__graph):
            current_node_number = greedy_hamiltonian_cycle[-1]

            for child_node_number in self.__graph[current_node_number].get_children():
                if (child_node_number in greedy_hamiltonian_cycle) or (child_node_number in visited_nodes):
                    continue
                greedy_hamiltonian_cycle.append(child_node_number)
                break

            if current_node_number == greedy_hamiltonian_cycle[-1]:
                break

        greedy_hamiltonian_cycle.append(start_node_number)
        return greedy_hamiltonian_cycle
    """
    def __branches_and_boundaries_algorithm(self, current_node_number: int, current_path: list[int], current_path_weight: int, visited_branches: list[list[bool]]) -> None:
        """
        This method searches for the minimum Hamiltonian cycle by the method of branches and boundaries
        :param current_path: list of node numbers in the current Hamiltonian path
        :param current_path_weight: weight of the current Hamiltonian path
        :return: None
        """
        #print(self.__best_hamiltonian_cycle_weight, current_path, current_path_weight, self.__lower_bound(current_node_number, current_path))
        if current_path_weight > self.__best_hamiltonian_cycle_weight:
            return

        if current_path_weight + self.__lower_bound(current_node_number, current_path) > self.__best_hamiltonian_cycle_weight:
            return

        if len(current_path) == len(self.__graph):
            if current_path_weight < self.__best_hamiltonian_cycle_weight:
                self.__best_hamiltonian_cycle_weight = current_path_weight
                self.__best_hamiltonian_cycle = current_path.copy()
            return

        while len(current_path) != len(self.__graph):
            next_node_number = self.__find_next_node(current_node_number, current_path, visited_branches)

            if next_node_number == -1:
                return

            new_path = current_path.copy()
            new_path_weight = current_path_weight + self.__graph.get_branch_weight(current_node_number, next_node_number)
            new_visited_branches = deepcopy(visited_branches)
            new_path.append(next_node_number)

            self.__branches_and_boundaries_algorithm(next_node_number, new_path, new_path_weight, new_visited_branches)

        """"
        if len(current_path) == len(self.__graph):
            new_path_weight = current_path_weight + self.__graph.get_branch_weight(current_path[-1], current_path[0])
            if new_path_weight < self.__best_hamiltonian_cycle_weight:
                new_path = deepcopy(current_path)
                new_path.append(current_path[0])
                self.__best_hamiltonian_cycle = new_path
                self.__best_hamiltonian_cycle_weight = new_path_weight
            return

        for node_number in range(len(self.__graph)):
            if node_number in current_path:
                continue
            current_path.append(node_number)
            current_path_weight += self.__graph.get_branch_weight(current_path[-2], current_path[-1])
            self.__branches_and_boundaries_algorithm(current_path, current_path_weight)
            current_path.pop()
        """
    def find_hamiltonian_cycle(self) -> list[int]:
        visited_branches = []
        for first_node_number in range(len(self.__graph)):
            visited_branches.append([])
            for second_node_number in range(len(self.__graph)):
                if self.__graph.get_branch_weight(first_node_number, second_node_number) == inf:
                    visited_branches[first_node_number].append(True)
                else:
                    visited_branches[first_node_number].append(False)

        self.__branches_and_boundaries_algorithm(self.__start_node, [], 0, visited_branches)
        self.__best_hamiltonian_cycle.insert(0, self.__start_node)

        return self.__best_hamiltonian_cycle


class App:
    """App - a class that is a wrapper over the solution of the problem"""

    def __init__(self, file_name: str) -> None:
        """
        This method initializes the initial parameters of the App
        :param file_name: the name of the file to read the graph
        """

        self.__init_graph(file_name)
        self.__solver = Solver(self.__graph)
        self.__answer_hamiltonian_cycle = None
        self.__answer_hamiltonian_cycle_weight = None
        self.__work_time = None

    def __init_graph(self, file_name: str) -> None:
        """
        A method that implements reading a graph from an input file
        :return: None
        """

        file = open(file_name, 'r')
        size = int(file.readline())
        self.__graph = Graph(size)

        node_number = 0
        for line in file:
            formatted_line = list(map(lambda x: inf if x.strip() in ["inf", "-"] else int(x), line.split()))
            for i in range(len(formatted_line)):
                self.__graph.set_branch_weight(node_number, i, formatted_line[i])
            node_number += 1

        file.close()

    def __format_answer(self) -> None:
        """
        This method translates the node numbers into the desired form
        :return: None
        """

        for i in range(len(self.__answer_hamiltonian_cycle)):
            self.__answer_hamiltonian_cycle[i] += 1

        self.__work_time = int(self.__work_time * 1000000)/1000

    def solve(self) -> None:
        """
        This method solves the whole problem
        :return: None
        """

        start_time = time()
        self.__graph.sort()
        self.__answer_hamiltonian_cycle = self.__solver.find_hamiltonian_cycle()
        self.__answer_hamiltonian_cycle_weight = self.__graph.get_path_weight(self.__answer_hamiltonian_cycle)
        self.__work_time = (time() - start_time)

    def __str__(self) -> str:
        """
        This method returns string version app answer
        :return:
        """

        if len(self.__answer_hamiltonian_cycle) != 1:
            self.__format_answer()
            return f"{self.__answer_hamiltonian_cycle}, {self.__answer_hamiltonian_cycle_weight}, {str(self.__work_time)}mc"
        else:
            return "No Hamiltonian cycle found"

    def __repr__(self) -> str:
        """This method returns official string version app answer"""

        return str(self)


def main():
    for i in range(1, 7):
        print('\n' + "-" * 15 + f"Test {i}" + "-" * 15)
        answer = App(f"test_{str(i)}.txt")
        answer.solve()
        print(answer)


if __name__ == "__main__":
    main()
