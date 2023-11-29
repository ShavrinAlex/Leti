class BohrNode:
    """
    This is the node class of the Bohr structure
    """

    def __init__(self) -> None:
        """
        This method initializes the initial node parameters needed to solve the problem
        """

        self.children_nodes = {}
        self.patterns_indexes = []
        self.suffix_link = None


class Solver:
    """
    This class solves the problem of finding occurrences of a substring in a string
    """

    def __init__(self, task_type: str = "Classic") -> None:
        """
        This method initializes the initial parameters needed to solve the problem
        """

        self.__task_type = task_type
        self.__bohr_root = BohrNode()
        self.__text = str()
        self.__patterns = list()
        self.__answer = list()

        self.__count_patterns = int()
        self.__pattern_parts_indexes = list()
        self.__joker_pattern = str()
        self.__joker_symbol = str()

    def __classic_input(self) -> None:
        """
        This method reads the input data for the classical algorithm
        :return: None
        """

        self.__text = input()
        self.__count_patterns = int(input())
        self.__patterns = [input() for _ in range(self.__count_patterns)]

    def __joker_input(self) -> None:
        """
        This method reads the input data for the algorithm with joker
        :return: None
        """

        self.__text = input()
        self.__joker_pattern = input()
        self.__joker_symbol = input()

    def __format_joker_input(self) -> None:
        """
        This method brings the given to the classical form, for using the classical algorithm
        :return: None
        """

        self.__patterns = list(filter(bool, self.__joker_pattern.split(self.__joker_symbol)))
        self.__count_patterns = len(self.__patterns)
        is_joker_symbol = True

        for index, symbol in enumerate(self.__joker_pattern):
            if symbol == self.__joker_symbol:
                is_joker_symbol = True
                continue
            if is_joker_symbol:
                self.__pattern_parts_indexes.append(index)
                is_joker_symbol = False

    def read_data(self) -> None:
        """
        This method reads given by the desired method, depending on the type of task
        :return: None
        """

        if self.__task_type == "Joker":
            self.__joker_input()
            self.__format_joker_input()
        else:
            self.__classic_input()

    def __build_bohr(self) -> None:
        """
        This method builds a bohr structure
        :return: None
        """

        for pattern_index in range(self.__count_patterns):
            current_node = self.__bohr_root

            for symbol in self.__patterns[pattern_index]:
                current_node = current_node.children_nodes.setdefault(symbol, BohrNode())

            current_node.patterns_indexes.append(pattern_index)

    def __build_suffix_links(self) -> None:
        """
        This method builds suffix links in the Bohr using a breadth-first crawl
        :return: None
        """

        queue = []
        for child_node in self.__bohr_root.children_nodes.values():
            child_node.suffix_link = self.__bohr_root
            queue.append(child_node)

        while len(queue) > 0:
            current_node = queue.pop(0)

            for symbol, child_node in current_node.children_nodes.items():
                queue.append(child_node)
                current_suffix_node = current_node.suffix_link

                while (current_suffix_node is not None) and (symbol not in current_suffix_node.children_nodes.keys()):
                    current_suffix_node = current_suffix_node.suffix_link

                if current_suffix_node:
                    child_node.suffix_link = current_suffix_node.children_nodes[symbol]
                else:
                    child_node.suffix_link = self.__bohr_root
                child_node.patterns_indexes += child_node.suffix_link.patterns_indexes

    def __aho_korasik_algorithm(self) -> None:
        """
        This method solves the problem using the classical Aho-Korasik algorithm
        :return: None
        """

        current_node = self.__bohr_root

        for symbol_index, symbol in enumerate(self.__text):
            while (current_node is not None) and (symbol not in current_node.children_nodes):
                current_node = current_node.suffix_link

            if current_node is None:
                current_node = self.__bohr_root
                continue

            current_node = current_node.children_nodes[symbol]
            for pattern_index in current_node.patterns_indexes:
                self.__answer.append((symbol_index - len(self.__patterns[pattern_index]) + 1, pattern_index))

        self.__answer = sorted(self.__answer)


    def __joker_aho_korasik_algorithm(self) -> None:
        """
        This method solves the problem with joker using the classical Aho-Korasik algorithm
        :return: None
        """

        self.__aho_korasik_algorithm()

        counter = [0] * len(self.__text)
        for aho_index, pattern_index  in self.__answer:
            joker_pattern_occurance_index = aho_index - self.__pattern_parts_indexes[pattern_index]
            if (joker_pattern_occurance_index >= 0) and \
                    (joker_pattern_occurance_index < len(self.__text)):
                counter[joker_pattern_occurance_index] += 1

        joker_answer = list()
        for index in range(len(self.__text) - len(self.__joker_pattern) + 1):
            if counter[index] == len(self.__patterns):
                joker_answer.append(index + 1)
        self.__answer = joker_answer

    def solve(self) -> None:
        """
        This method solves the problem with the right method, depending on the type of task
        :return: None
        """

        self.__build_bohr()
        self.__build_suffix_links()
        if self.__task_type == "Joker":
            self.__joker_aho_korasik_algorithm()
        else:
            self.__aho_korasik_algorithm()

    def print_answer(self) -> None:
        """
        This method outputs the answer in the format that a particular task requires
        :return: None
        """

        if self.__task_type == "Joker":
            print(*self.__answer, sep='\n')
        else:
            for pair in self.__answer:
                print(f"{pair[0] + 1} {pair[1] + 1}")


def main():
    """
    This function solves the problem
    :return: None
    """
    #solver = Solver("Joker")
    solver = Solver()
    solver.read_data()
    solver.solve()
    solver.print_answer()


if __name__ == "__main__":
    main()
