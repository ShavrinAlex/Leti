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
        BohrNode* output_link;
        int pattern_index;

    public:
        BohrNode();
        std::map<char, BohrNode*> getChildrenNodes();
        BohrNode* getChild(char suffix);
        void setChild(char suffix, BohrNode* child_node);
        int getPatternIndex();
        void setPatternIndex(int pattern_index);
        BohrNode* getSuffixLink();
        void setSuffixLink(BohrNode* suffix_node);
        BohrNode* getOutputLink();
        void setOutputLink(BohrNode* output_node);
};

BohrNode::BohrNode(){
    this->suffix_link = nullptr;
    this->output_link = nullptr;
    this->pattern_index = -1;
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

int BohrNode::getPatternIndex(){
    return this->pattern_index;
};

void BohrNode::setPatternIndex(int pattern_index){
    this->pattern_index = pattern_index;
};

BohrNode* BohrNode::getSuffixLink(){
    return this->suffix_link;
};

void BohrNode::setSuffixLink(BohrNode* suffix_node){
    this->suffix_link = suffix_node;
};

BohrNode* BohrNode::getOutputLink(){
    return this->output_link;
};

void BohrNode::setOutputLink(BohrNode* output_node){
    this->output_link = output_node;
};


class Solver{
    private:
        TaskTypes task_type;
        BohrNode* bohr_root;
        std::string text;
        size_t count_patterns;
        std::vector<std::string> patterns;
        std::vector<std::pair<int, int>> patterns_occurrence_indexes;

        void buildBohr();
        void buildSuffixAndOutputLinks();
        void classicInput();
        void jokerInput();
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
            break;
        default:
            this->classicInput();
            break;
    }
    
    this->bohr_root = new BohrNode();
    this->buildBohr();
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

};

void Solver::buildBohr(){
    for (size_t index = 0; index < this->count_patterns; index++){
        BohrNode* current_node = this->bohr_root;

        for (char symbol : patterns.at(index)){
            if (current_node->getChild(symbol) != nullptr){
                current_node = current_node->getChild(symbol);
            } else {
                BohrNode* child = new BohrNode();
                current_node->setChild(symbol, child);
                current_node = child;
            }
        }
        current_node->setPatternIndex(index);
    }
};

void Solver::buildSuffixAndOutputLinks(){
    this->bohr_root->setSuffixLink(this->bohr_root);
    
    std::queue<BohrNode*> queue;

    for(auto &iterator : this->bohr_root->getChildrenNodes()){
        iterator.second->setSuffixLink(this->bohr_root);
        queue.push(iterator.second);
    }

    while(queue.size()){
        BohrNode* current_node = queue.front();
        queue.pop();

        for(auto &iterator : current_node->getChildrenNodes()){
            char suffix = iterator.first;
            BohrNode* temp_node = current_node->getSuffixLink();
            
            while(temp_node->getChild(suffix) == nullptr && temp_node != this->bohr_root){
                temp_node = temp_node->getSuffixLink();
            }

            if(temp_node->getChild(suffix) != nullptr){
                iterator.second->setSuffixLink(temp_node->getChild(suffix));
            } else {
                iterator.second->setSuffixLink(this->bohr_root);
            } 

            queue.push(iterator.second);
        }

        if(current_node->getSuffixLink()->getPatternIndex() >= 0){
            current_node->setOutputLink(current_node->getSuffixLink());
        } else {
            current_node->setOutputLink(current_node->getSuffixLink()->getOutputLink());
        }
    }
};

void Solver::solveClassic(){
    this->buildSuffixAndOutputLinks();

    BohrNode* parent_node = this->bohr_root;

    for (int index = 0; index < this->text.length(); index++){
        char symbol = this->text[index];

        if (parent_node->getChild(symbol) != nullptr){
            parent_node = parent_node->getChild(symbol);

            if (parent_node->getPatternIndex() >= 0){
                int pattern_size =  this->patterns.at(parent_node->getPatternIndex()).size();
                this->patterns_occurrence_indexes.emplace_back(std::pair<int, int>(index  - pattern_size + 1, parent_node->getPatternIndex()));
            }

            BohrNode* temp_node = parent_node->getOutputLink();
            while (temp_node != nullptr){ 
                int pattern_size =  this->patterns.at(temp_node->getPatternIndex()).size();
                this->patterns_occurrence_indexes.emplace_back(std::pair<int, int>(index  - pattern_size + 1, temp_node->getPatternIndex()));
                temp_node = temp_node->getOutputLink();
            }
        } else {
            while (parent_node != this->bohr_root && parent_node->getChild(symbol) == nullptr){
                parent_node = parent_node->getSuffixLink();
            }

            if (parent_node->getChild(symbol) != nullptr){
                index--;
            }
        }
    }
};

void Solver::solveJoker(){

};

void Solver::printClassic(){
    std::sort(this->patterns_occurrence_indexes.begin(), this->patterns_occurrence_indexes.end(), cmp);
    for (auto pair : this->patterns_occurrence_indexes){
        int occurance_index = pair.first;
        int pattern_index = pair.second;
        std::cout << occurance_index + 1 << ' ' << pattern_index + 1 << std::endl;
    }
};

void Solver::printJoker(){

};

void Solver::solve(){
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
    Solver *solver = new Solver();
    solver->solve();
    solver->printAnswer();
    return 0;
};
