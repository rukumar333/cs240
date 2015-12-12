#ifndef Graph_H
#define Graph_H
#include "LinkedList.h"
#include <unordered_map>

class Graph{
 public:
    int capacity;
    int length = 0;
    std::unordered_map<std::string, int> hashmap;
    LinkedList * vertices;
    Graph();
    ~Graph();
    void setCapacity(int cap);
    void addVertex(std::string city);    
    void addEdge(std::string from, std::string to);
};

#endif
