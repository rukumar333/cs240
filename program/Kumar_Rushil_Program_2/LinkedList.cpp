#include "LinkedList.h"

LinkedList::LinkedList(){
    head = nullptr;
    tail = nullptr;
}

LinkedList::~LinkedList(){
    Node * iterator = head;
    Node * tmp = nullptr;
    if(iterator){
	while(iterator){
	    tmp = iterator->next;
	    delete iterator;
	    iterator = tmp;	    
	}
    }
}

void LinkedList::append(Song song, int num){
    Node * np = new Node();
    np->data = num;
    np->song = song;
    if(head){
    	tail->next = np;
    	np->previous = tail;
    	tail = np;
    }else{
    	head = np;
    	tail = np;
    }
}

void LinkedList::show(){
    Node * iterator = head;
    while(iterator){
	std::cout << iterator->data << std::endl;
	iterator = iterator->next;
    }
}
