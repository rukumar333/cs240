#ifndef LinkedList_H
#define LinkedList_H

#include <iostream>
#include <string>
#include "Song.h"
#include "Time.h"

class LinkedList{
 public:
    class Node{
    public:	
	Node * next = NULL;
	Node * previous = NULL;
	int data;
	Song song;
    };
    //Destructor
    ~LinkedList();
    //Default Constructor
    LinkedList();
    Node * head;
    Node * tail;
    void append(Song song, int num);
    void show();
};

#endif
