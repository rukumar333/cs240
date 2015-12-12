#ifndef LinkedList_H
#define LinkedList_H

#include <iostream>
#include <string>

class LinkedList{
 public:
    class Node{
    public:
	Node * next = nullptr;
	Node * previous = nullptr;
	std::string data;
	int arrPos;
    };
    Node * head = nullptr;
    Node * tail = nullptr;
    std::string startCity;
    LinkedList();
    ~LinkedList();
    void append(std::string city, int arrPos);    
};

#endif
