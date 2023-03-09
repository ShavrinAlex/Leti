#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

class Node{
    private:
        char name;
        std::map <Node*, int> children;
        std::vector <Node*> visited_children;

    public:
        Node(char name);
        char getName();
        void addChild(Node* child_node, int weight);
        std::map <Node*, int> getChildren();
        bool isVisitedChild(Node* child_node);
        void addVisitedChild(Node*node);
};

Node::Node(char name){
    this->name = name;
};

bool Node::isVisitedChild(Node* child_node){
    return std::binary_search(this->visited_children.begin(), this->visited_children.end(), child_node);
    /*
    for (size_t i = 0; i < this->visited_children.size(); i++){
        if (child_node == this->visited_children.at(i)){
            return true;
        }
    }
    return false;
    */
};

char Node::getName(){
    return this->name;
};

void Node::addChild(Node* child_node, int weight){
    this->children.insert(std::pair <Node*, int>(child_node, weight));
};

std::map <Node*, int> Node::getChildren(){
    return this->children;
};

void Node::addVisitedChild(Node* node){
    if (this->isVisitedChild(node)){
        return;
    }

    for (auto i = this->children.begin(); i != this->children.end(); ++i){
        if (node == i->first){
            this->visited_children.emplace_back(node);
        }
    }
};






class Graph{
    private:
        std::vector <Node*> nodes;

        bool isPresentNode(char node_name);

    public:
        Graph();
        void addBranch(char first_node_name, char second_node_name, int weight);
        Node* getNode(char node_name);
        ~Graph();
};

Graph::Graph(){
    this->nodes.reserve(10);
};

bool Graph::isPresentNode(char node_name){
    for (size_t i = 0; i < this->nodes.size(); i++){
        if (node_name == this->nodes.at(i)->getName()){
            return true;
        }
    }
    return false;
};

Node* Graph::getNode(char node_name){
    Node* node = nullptr;
    for (auto i = 0; i < this->nodes.size(); i++){
        if (node_name == this->nodes.at(i)->getName()){
            node = this->nodes.at(i);
            break;
        }
    }
    return node;
};

void Graph::addBranch(char first_node_name, char second_node_name, int weight){
    Node* first_node = nullptr;
    Node* second_node = nullptr;

    if (this->isPresentNode(first_node_name)){
        first_node = this->getNode(first_node_name);
    } else {
        first_node = new Node(first_node_name);
        this->nodes.emplace_back(first_node);
    }

    if (this->isPresentNode(second_node_name)){
        second_node = this->getNode(second_node_name);
    } else {
        second_node = new Node(second_node_name);
        this->nodes.emplace_back(second_node);
    }

    first_node->addChild(second_node, weight);
};

Graph::~Graph(){
    for (size_t i = 0; i < this->nodes.size(); i++){
        delete this->nodes.at(i);
    }
};






class Solution{
    private:
        Graph* graph;
        std::vector <Node*> path;
        char start_node_name;
        char end_node_name;

        Node* getBestChild(Node* node);

    public:
        Solution();
        void greadyAlgorithm();
        void AStarAlgorithm();
        void printPath();
        ~Solution();

};

Node* Solution::getBestChild(Node* node){
    int min_weight = 10000;
    Node* best_child = nullptr;
    auto children = node->getChildren();

    for (auto i = children.begin(); i != children.end(); ++i){
        if (node->isVisitedChild(i->first) == false){
            if (i->second < min_weight){
                min_weight = i->second;
                best_child = i->first;
            }
        }
    }

    node->addVisitedChild(best_child);
    return best_child;
};


Solution::Solution(){
    std::cin >> this->start_node_name >> this->end_node_name;
    
    this->graph = new Graph();

    char first_node_name;
    char second_node_name;
    float weight;

    while (std::cin >> first_node_name >> second_node_name >> weight){
        this->graph->addBranch(first_node_name, second_node_name, weight);
    }
};

void Solution::greadyAlgorithm(){
    Node* best_node = this->graph->getNode(this->start_node_name);
    this->path.emplace_back(best_node);

    while (best_node->getName() != this->end_node_name){
        best_node = this->getBestChild(best_node);

        while (best_node == nullptr || std::binary_search(this->path.begin(), this->path.end(), best_node)){
            this->path.pop_back();
            best_node = this->path.back();
            this->path.pop_back();
        }
        this->path.emplace_back(best_node);
    }
};

void Solution::AStarAlgorithm(){
    return;
};

void Solution::printPath(){
    for (size_t i = 0; i < this->path.size(); i++){
        std::cout << this->path.at(i)->getName();
    }
    std::cout << std::endl;
};

Solution::~Solution(){
    delete this->graph;

    for (size_t i = 0; i < this->path.size(); i++){
        this->path.at(i) = nullptr;
    }
};






int main(){
    Solution a_star = Solution();
    a_star.greadyAlgorithm();
    a_star.printPath();
    return 0;
}