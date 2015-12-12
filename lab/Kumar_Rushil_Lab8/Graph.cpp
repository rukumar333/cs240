#include "Graph.h"

Graph::Graph(){
    vertices = nullptr;
    hashmap = std::unordered_map<std::string, int>();
}

Graph::~Graph(){
    delete[] vertices;
}

void Graph::setCapacity(int cap){
    capacity = cap;
    vertices = new LinkedList[cap];    
}

void Graph::addVertex(std::string city){
    hashmap[city] = length;
    
}

void Graph::addEdge(std::string from, std::string to){
    
}
