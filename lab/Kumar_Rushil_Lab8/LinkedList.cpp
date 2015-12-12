#include "LinkedList.h"

LinkedList::LinkedList(){    
}

LinkedList::~LinkedList(){
    Node * iterator = head;
    Node * tmp = head;
    while(iterator){
	tmp = iterator->next;
	delete iterator;
	iterator = tmp;
    }
}

void LinkedList::append(std::string city, int arrPos){
    Node * np = new Node();
    np->data = city;
    np->arrPos = arrPos;
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
	std::cout << iterator->data << " (" << iterator->arrPos << ")" << std::endl;
	iterator = iterator->next;
    }
}
