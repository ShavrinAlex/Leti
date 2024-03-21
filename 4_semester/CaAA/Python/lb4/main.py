import sys
import re


class Solver:
    """
    This class solves the problem of finding occurrences of a substring in a string
    """

    def __init__(self) -> None:
        """
        This method initializes the initial parameters needed to solve the problem
        """

        self.__first_string = ""
        self.__second_string = ""

        self.__read_data()

    def __read_data(self) -> None:
        """
        This method reads the input data
        :return: None
        """

        input_data = sys.stdin.read()
        split_input_data = re.split(r" |\n|\t| \t|\t ", input_data)
        self.__first_string, self.__second_string = split_input_data[0], split_input_data[1]

    @staticmethod
    def prefix_function(string: str) -> list[int]:
        """
        This method compiles a list of prefix lengths matching suffixes from the passed string
        :param string: the string to build the list for
        :return: a list of prefix lengths matching suffixes from the passed string
        """

        prefix_indexes = [0 for _ in range(len(string))]

        for i in range(1, len(string)):
            prefix_suffix_length = prefix_indexes[i - 1]

            while (prefix_suffix_length > 0) and (string[i] != string[prefix_suffix_length]):
                prefix_suffix_length = prefix_indexes[prefix_suffix_length - 1]

            if string[i] == string[prefix_suffix_length]:
                prefix_suffix_length += 1

            prefix_indexes[i] = prefix_suffix_length

        return prefix_indexes

    def kmp_algorithm(self) -> list[int]:
        """
        This method solves the problem of finding a substring in a string by the Knuth-Morris-Pratt algorithm
        :return: None
        """
        occurrence_indexes = list()
        combined_strings = self.__first_string + "@" + self.__second_string
        prefix_indexes = self.prefix_function(combined_strings)
        pattern_len = len(self.__first_string)

        for index in range(pattern_len + 1, len(combined_strings)):
            if prefix_indexes[index] == pattern_len:
                occurrence_indexes.append(index - 2*(pattern_len + 1))

        return occurrence_indexes

    def cycle_shift_algorithm(self) -> int:
        """

        :return: index of the beginning of the text string in the pattern
        """

        answer = -1
        if len(self.__first_string) != len(self.__second_string):
            return answer
        if len(self.__first_string) == 0 or len(self.__second_string) == 0:
            return answer

        if self.__second_string in (self.__first_string + self.__first_string):
            answer = (self.__first_string + self.__first_string).index(self.__second_string)

        return answer


def main():
    solver = Solver()
    print(solver.kmp_algorithm())
    #print(solver.cycle_shift_algorithm())


if __name__ == "__main__":
    main()
