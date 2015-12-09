#ifndef LinkedList_H
#define LinkedList_H

#include <iostream>
#include <string>

class LinkedList{
 public:
    class Node{
	Node * next;
	Node * previous;
	std::string data;
    };
    Node * head;
    Node * tail;
    void append();  	
};

#endif
