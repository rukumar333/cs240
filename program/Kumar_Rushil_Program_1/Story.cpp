#include "Story.h"
#include <iostream>

Story::Story(){
    std::cout << "Story Default constructor" << std::endl;
}

Story::~Story(){
    std::cout << "Story destructor" << std::endl;
    Node_P * iterator = head;
    Node_P * tempPointer = head;
    while(iterator != nullptr){
    	std::cout << "Deleting" << std::endl;
    	iterator = iterator->next;
    	delete tempPointer;	
    	tempPointer = iterator;
    }
}    

Story::Story(const Story &s1){
    std::cout << "Story copy constructor" << std::endl;
    Node_P * iterator = s1.head;
    if(!iterator){
    	head = NULL;
    	tail = NULL;
    }
    while(iterator != nullptr){
    	this->append(iterator->data);
    	iterator = iterator->next;
    }
}

Story Story::operator+(const Story &s1){
    std::cout << "Story + Story" << std::endl;
}
Story Story::operator+(const Paragraph &p1){
    std::cout << "Story + Paragraph" << std::endl;    
}
Story Story::operator+(const int &i){
    std::cout << "Story + 1 (all other ints should be ignored)" << std::endl; 
}
Story Story::operator++(int){
    std::cout << "Story++" << std::endl;     
}
Story Story::operator--(int){
    std::cout << "Story--" << std::endl;     
}
Story Story::operator++(){
    std::cout << "++Story" << std::endl;     
}
Story Story::operator--(){
    std::cout << "--Story" << std::endl;     
}
Story & Story::operator=(const Story &s1){
    std::cout << "Story assignment operator" << std::endl;     
    this->head = NULL;
    this->tail = NULL;
    Node_P * iterator = s1.head;
    if(!iterator){
    	head = NULL;
    	tail = NULL;
    }
    while(iterator != nullptr){
    	this->append(iterator->data);
    	iterator = iterator->next;
    }
}

void Story::append(const Paragraph &p){
    std::cout << "APPENDING STORY" << std::endl;
    Node_P* node = new Node_P();
    node->data = p;
    if(head == NULL && tail == NULL){
	head = node;
	tail = node;
    }else{
	tail->next = node;
	tail = node;	
    }
}

void Story::prepend(const Paragraph &p){
    Node_P* node = new Node_P();
    node->data = p;
    if(head == NULL && tail == NULL){
	head = node;
	tail = node;
    }else{
	node->next = head;
	head = node;
    }    
}

void Story::show(){
    std::cout << "Story show used" << std::endl;
    Node_P* iterator = head;
    while(iterator != nullptr){
	if(iterator == tail){
	    iterator->data.show();
	    iterator = iterator->next;   	    
	}else{
	    iterator->data.show();
	    std::cout << '\n';
	    iterator = iterator->next;   
	}
    }
}

std::ostream & operator<<(std::ostream & os, const Story &s1){
    std::cout << "Bitshift for story used";
    return os;
}
