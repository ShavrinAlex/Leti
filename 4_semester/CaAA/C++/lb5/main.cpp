#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>


#define ALPHABET 5
enum TaskTypes {Classic, Joker};

bool cmp(const std::pair<int, int> &a, const std::pair<int, int> &b){
    if (a.first != b.first){
        return a.first < b.first;
    }
    return a.second < b.second;
}


class BohrNode{
    private:
        std::map<char, BohrNode*> children_nodes;
        BohrNode* suffix_link;
        std::vector<int> patterns_indexes;

    public:
        BohrNode();
        std::map<char, BohrNode*> getChildrenNodes();
        BohrNode* getChild(char suffix);
        void setChild(char suffix, BohrNode* child_node);
        std::vector<int> getPatternsIndexes();
        void addPatternIndex(size_t pattern_index);
        BohrNode* getSuffixLink();
        void setSuffixLink(BohrNode* suffix_node);
};

BohrNode::BohrNode(){
    this->suffix_link = nullptr;
};

std::map<char, BohrNode*> BohrNode::getChildrenNodes(){
    return this->children_nodes;
};

BohrNode* BohrNode::getChild(char suffix){
    auto iterator = this->children_nodes.find(suffix);
    if (iterator != this->children_nodes.end()){
        return iterator->second;
    }
    return nullptr;
};

void BohrNode::setChild(char suffix, BohrNode* child_node){
    auto iterator = this->children_nodes.find(suffix);
    if (iterator == this->children_nodes.end()){
        this->children_nodes.insert({suffix, child_node});
    } else {
        iterator->second = child_node;
    }
};

std::vector<int> BohrNode::getPatternsIndexes(){
    return this->patterns_indexes;
};

void BohrNode::addPatternIndex(size_t pattern_index){
    this->patterns_indexes.emplace_back(pattern_index);
};

BohrNode* BohrNode::getSuffixLink(){
    return this->suffix_link;
};

void BohrNode::setSuffixLink(BohrNode* suffix_node){
    this->suffix_link = suffix_node;
};


class Solver{
    private:
        TaskTypes task_type;
        BohrNode* bohr_root;
        std::string text;
        std::vector<std::string> patterns;
        std::vector<std::pair<int, int>> patterns_occurrence_indexes;

        size_t count_patterns;
        std::string joker_pattern;
        char jokerSymbol;
        std::vector<int> indexes_of_pattern_parts;
        std::vector<int> joker_pattern_occurence_indexes;

        void buildBohr();
        void buildSuffixAndOutputLinks();
        void classicInput();
        void jokerInput();
        void formatJokerInputData();
        void solveClassic();
        void solveJoker();
        void printClassic();
        void printJoker();

    public:
        Solver(TaskTypes task_type);
        void solve();
        void printAnswer();
};

Solver::Solver(TaskTypes task_type=Classic){
    this->task_type = task_type;
    
    switch (this->task_type){
        case Classic: 
            this->classicInput();
            break;
        case Joker:
            this->jokerInput();
            this->formatJokerInputData();
            break;
        default:
            this->classicInput();
            break;
    }
    
    this->bohr_root = new BohrNode();
};

void Solver::classicInput(){
    std::cin >> this->text;
    std::cin >> this->count_patterns;
    
    for(size_t i = 0; i < this->count_patterns; i++){
        std::string pattern;
        std::cin >> pattern;
        patterns.push_back(pattern);
    }  
};

void Solver::jokerInput(){
    std::cin >> this->text;
    std::cin >> this->joker_pattern;
    std::cin >> this->jokerSymbol;
};

void Solver::formatJokerInputData(){
    std::string input_pattern = this->joker_pattern + this->jokerSymbol;
    size_t joker_index = 0;
    size_t index_occurance_part = 0;
    while ((joker_index = input_pattern.find(this->jokerSymbol)) != std::string::npos){
        std::string pattern_part = input_pattern.substr(0, joker_index);
        input_pattern.erase(0, joker_index + 1);
        if (pattern_part.size() != 0 && pattern_part != input_pattern){
            this->patterns.push_back(pattern_part);
            this->indexes_of_pattern_parts.push_back(index_occurance_part);
        }
        index_occurance_part += joker_index + 1;
    }
};

void Solver::buildBohr(){
    for (size_t index = 0; index < this->count_patterns; index++){
        BohrNode* current_node = this->bohr_root;

        for (char symbol : patterns.at(index)){
            if (current_node->getChild(symbol) == nullptr){
                current_node->setChild(symbol, new BohrNode());
            }
            current_node = current_node->getChild(symbol);
        }
        current_node->addPatternIndex(index);
    }
};

void Solver::buildSuffixAndOutputLinks(){
    std::queue<BohrNode*> queue;

    for(auto &iterator : this->bohr_root->getChildrenNodes()){
        iterator.second->setSuffixLink(this->bohr_root);
        queue.push(iterator.second);
    }

    while(queue.size() > 0){
        BohrNode* current_node = queue.front();
        queue.pop();

        for(auto &iterator : current_node->getChildrenNodes()){
            char suffix = iterator.first;
            BohrNode* child_node = iterator.second;

            queue.push(child_node);
            BohrNode* suffix_link_node = current_node->getSuffixLink();
            
            while(suffix_link_node != nullptr && suffix_link_node->getChild(suffix) == nullptr){
                suffix_link_node = suffix_link_node->getSuffixLink();
            }

            if(suffix_link_node != nullptr){
                child_node->setSuffixLink(suffix_link_node->getChild(suffix));
            } else {
                child_node->setSuffixLink(this->bohr_root);
            } 
            for (size_t pattern_index : child_node->getSuffixLink()->getPatternsIndexes()){
                child_node->addPatternIndex(pattern_index);
            }
        }
    }
};

void Solver::solveClassic(){
    BohrNode* current_node = this->bohr_root;

    for (int index = 0; index < this->text.length(); index++){
        char symbol = this->text[index];
        
        while (current_node != nullptr && current_node->getChild(symbol) == nullptr){
            current_node = current_node->getSuffixLink();
        }

        if (current_node == nullptr){
            current_node = this->bohr_root;
            continue;
        }

        current_node = current_node->getChild(symbol);
        for (size_t pattern_index : current_node->getPatternsIndexes()){
            int pattern_size =  this->patterns.at(pattern_index).size();
            this->patterns_occurrence_indexes.emplace_back(std::pair<int, int>{index - pattern_size + 1, pattern_index});
        }
    }
    std::sort(this->patterns_occurrence_indexes.begin(), this->patterns_occurrence_indexes.end(), cmp);
};

void Solver::solveJoker(){
    this->solveClassic();
    std::cout<<"occurence part indexes\n";
    for (auto p : this->patterns_occurrence_indexes){
        std::cout<<p.first<<' '<<p.second<<'\n';
    }
    std::cout<<"occurence part indexes\n";
    
    std::vector<int> c(this->text.size());
    for (auto pair : this->patterns_occurrence_indexes){
        int occurance_index = pair.first;
        int pattern_index = pair.second;
        int idx = occurance_index - this->indexes_of_pattern_parts.at(pattern_index);
        if (idx >= 0 && idx < c.size()){
            c.at(idx) += 1;
        }
    }

    for (int i = 0; i < this->text.size() - this->joker_pattern.size() + 1; i++){
        if (c.at(i) == this->joker_pattern.size()){
            this->joker_pattern_occurence_indexes.push_back(i);
        }
    }
};

void Solver::printClassic(){
    for (auto pair : this->patterns_occurrence_indexes){
        int occurance_index = pair.first;
        int pattern_index = pair.second;
        std::cout << occurance_index + 1 << ' ' << pattern_index + 1 << std::endl;
    }
};

void Solver::printJoker(){
    for (int occurence_index: this->joker_pattern_occurence_indexes){
        std::cout << occurence_index + 1 << std::endl;
    }
};

void Solver::solve(){
    this->buildBohr();
    this->buildSuffixAndOutputLinks();

    switch (this->task_type){
        case Classic: 
            this->solveClassic();
            break;
        case Joker:
            this->solveJoker();
            break;
        default:
            this->solveClassic();
            break;
    }
    
};

void Solver::printAnswer(){
    switch (this->task_type){
        case Classic: 
            this->printClassic();
            break;
        case Joker:
            this->printJoker();
            break;
        default:
            this->printClassic();
            break;
    }
};


int main(){
    Solver *solver = new Solver(Joker);
    solver->solve();
    solver->printAnswer();
    return 0;
};
