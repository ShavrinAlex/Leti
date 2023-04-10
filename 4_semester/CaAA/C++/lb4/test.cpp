#include <iostream>
#include <vector>


/**
 * This class solves the problem of finding occurrences of a substring in a string
**/
class Solver{
    private:
        std::string first_string;                            // first input string
        std::string second_string;                           // second input string
        std::vector<int> prefixFunction(std::string string); // prefix function for the Knuth-Morris-Pratt method

    public:
        Solver();                                            // class constructor
        std::string KMPAlgorithm();                          // Knuth-Morris-Pratt algorithm
        int cycleShiftAlgorithm();                           // the method that determines the cyclic shift
};

/**
 * This method initializes the initial parameters needed to solve the problem (reads the input data)
**/
Solver::Solver(){
    std::cin >> this->first_string;
    std::cin >> this->second_string;
};

/**
 * This method compiles a list of prefix lengths matching suffixes from the passed string
 * Args:
 * - string (std::string) - he string to build the list for
 * Returns:
 * - prefix_indexes (std::vector<int>) -  a list of prefix lengths matching suffixes from the passed string
**/
std::vector<int> Solver::prefixFunction(std::string string){
    std::vector<int> prefix_indexes(string.size(), 0);

    for (size_t i = 1; i < string.size(); i++){
        int j = prefix_indexes[i - 1];
        
        while ((j > 0) && (string[i] != string[j])){
            j = prefix_indexes[j - 1];
        }

        if (string[i] == string[j]){
                j++;
        }

        prefix_indexes[i] = j;
    }

    return prefix_indexes;
};

/**
 * This method solves the problem of finding a substring in a string by the Knuth-Morris-Pratt algorithm
 * Returns:
 * - occurrence_indexes (std::string) - indexes of the occurrence of the first row in the second
**/
std::string Solver::KMPAlgorithm(){
    std::string occurrence_indexes;
    std::string combined_strings = this->first_string + "@" + this->second_string;
    std::vector<int> prefix_indexes = this->prefixFunction(combined_strings);
    size_t pattern_len = this->first_string.size();

    for (size_t index = 1; index < this->second_string.size(); index++){
        if (prefix_indexes[pattern_len + 1 + index] == pattern_len){
            occurrence_indexes += std::to_string(index - pattern_len + 1) + ",";
        }
    }

    if (occurrence_indexes.size() == 0){
        occurrence_indexes = "-1";
    } else {
        occurrence_indexes.erase(occurrence_indexes.find_last_not_of(",") + 1);
    }

    return occurrence_indexes;
};

/**
 * This method determines whether the first row is a cyclic shift of the second
 * Returns:
 * - answer (int) - index of the beginning of the second row in the first
**/
int Solver::cycleShiftAlgorithm(){
    int answer = -1;

    if (this->first_string.size() != this->second_string.size()){
        return answer;
    }

    if (this->first_string.size() == 0 || this->second_string.size() == 0){
        return answer;
    }

    std::vector<int> prefix_indexes = this->prefixFunction(this->second_string);
    size_t first_string_len = first_string.size();
    size_t second_string_len = second_string.size();

    for (size_t index = 0; index < first_string_len; index++){
        size_t first_string_index = index;
        size_t second_string_index = 0;

        while (first_string_index < first_string_len * 2 + index){
            size_t first_string_real_index = first_string_index % first_string_len;

            if (this->first_string[first_string_real_index] == this->second_string[second_string_index]){
                first_string_index++;
                second_string_index++;

                if (second_string_index == second_string_len){
                    answer = first_string_index - second_string_index;
                    return answer;
                }
            } else {

                if (second_string_index > 0){
                    second_string_index = prefix_indexes.at(second_string_index - 1);
                } else {
                    first_string_index++;
                }

            }
        }
    }

    return answer;
};


/**
 * The main function that implements the solution of the problem
**/
int main(){
    Solver* solver = new Solver();
    //std::cout << solver->KMPAlgorithm() << std::endl;
    std::cout << solver->cycleShiftAlgorithm() << std::endl;
    delete solver;
    return 0;
}

