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

        bool isVisitedChild(Node* child_node);

    public:
        Node(char name);
        char getName();
        void addChild(Node* child_node, int weight);
        Node* getBestChild(char end_node_name);
};

Node::Node(char name){
    this->name = name;
};

bool Node::isVisitedChild(Node* child_node){
    for (size_t i = 0; i < this->visited_children.size(); i++){
        if (child_node == this->visited_children.at(i)){
            return true;
        }
    }
    return false;
};

char Node::getName(){
    return this->name;
};

void Node::addChild(Node* child_node, int weight){
    this->children.insert(std::pair <Node*, int>(child_node, weight));
};

Node* Node::getBestChild(char end_node_name){
    int heuristics;
    Node* best_child = nullptr;

    for (auto i = this->children.begin(); i != this->children.end(); ++i){
        if (this->isVisitedChild(i->first) == false){
            int tmp_heuristics = abs((int)end_node_name - (int)i->first->getName()) + i->second;

            if (best_child == nullptr){
                best_child = i->first;
                heuristics = tmp_heuristics;
            } else{
                if ((tmp_heuristics < heuristics) || (tmp_heuristics == heuristics && (int)i->first->getName() > (int)best_child->getName())){
                    best_child = i->first;
                    heuristics = tmp_heuristics;
                }
            }
        }
    }

    this->visited_children.emplace_back(best_child);
    return best_child;
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






class AStar{
    private:
        Graph* graph;
        std::vector <Node*> path;
        char start_node_name;
        char end_node_name;

    public:
        AStar();
        void justDoIt();
        void printPath();
        ~AStar();

};

AStar::AStar(){
    std::cin >> this->start_node_name >> this->end_node_name;
    
    this->graph = new Graph();

    char first_node_name;
    char second_node_name;
    float weight;

    while (std::cin >> first_node_name >> second_node_name >> weight){
        //std::cout<<first_node_name << second_node_name << weight<<'\n';
        this->graph->addBranch(first_node_name, second_node_name, weight);
    }
};

void AStar::justDoIt(){
    Node* best_node = this->graph->getNode(this->start_node_name);
    this->path.emplace_back(best_node);

    while (best_node->getName() != this->end_node_name){

        best_node = best_node->getBestChild(this->end_node_name);

        while (best_node == nullptr || std::binary_search(this->path.begin(), this->path.end(), best_node)){
            this->path.pop_back();
            best_node = this->path.back();
            this->path.pop_back();
        }
        this->path.emplace_back(best_node);
        //this->printPath();
    }
};

void AStar::printPath(){
    for (size_t i = 0; i < this->path.size(); i++){
        std::cout << this->path.at(i)->getName();
    }
    std::cout << std::endl;
};

AStar::~AStar(){
    delete this->graph;

    for (size_t i = 0; i < this->path.size(); i++){
        this->path.at(i) = nullptr;
    }
};






int main(){
    AStar a_star = AStar();
    a_star.justDoIt();
    a_star.printPath();
    return 0;
}