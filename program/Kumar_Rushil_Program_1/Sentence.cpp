#include "Sentence.h"
#include "Paragraph.h"
#include <iostream>

Sentence::Sentence(){
    // std::cout << "Sentence Default constructor" << std::endl;
}

Sentence::~Sentence(){
    // std::cout << "Sentence destructor" << std::endl;
    // std::cout << this << std::endl;
    // this->show();
    Node_W * iterator = head;
    Node_W * tempPointer = head;
    // std::cout << iterator << std::endl;
    while(iterator){
	iterator = iterator->next;
	delete tempPointer;	
	tempPointer = iterator;
    }
    head = NULL;
    tail = NULL;    
}    

Sentence::Sentence(const Sentence &s1){
    // std::cout << "Sentence Copy Constructor" << std::endl;
    Node_W * iterator = s1.head;
    if(!iterator){
	head = NULL;
	tail = NULL;
    }
    while(iterator != nullptr){
	this->append(iterator->data);
	iterator = iterator->next;
    }
}

Paragraph Sentence::operator+(const Sentence &s1){
    Paragraph p;
    p.append(*this);
    p.append(s1);
    return p;
}
Paragraph Sentence::operator+(const Paragraph &p1){
    Paragraph p = p1;
    p.prepend(*this);
    return p;
}
Sentence Sentence::operator+(const Word &p1){    
    Sentence temp = *this;
    temp.append(p1);
    return temp;
}
Sentence Sentence::operator+(const int &i){
    if(i != 1){
	return * this;
    }
    Node_W * iterator = head;
    while(iterator){
	(iterator->data) + 1;
	iterator = iterator->next;;
    }
    return *this;
}
Sentence Sentence::operator++(int){
    Node_W * iterator = head;
    while(iterator != nullptr){
	(iterator->data)++;
	iterator = iterator->next;
    }
    return *this;
}
Sentence Sentence::operator--(int){
    Node_W * iterator = head;
    while(iterator){
	(iterator->data)--;
	iterator = iterator->next;;
    }
    return *this;
}
Sentence Sentence::operator++(){
    Node_W * iterator = head;
    while(iterator){
	++(iterator->data);
	iterator = iterator->next;;
    }
    return *this;
}
Sentence Sentence::operator--(){
    Node_W * iterator = head;
    while(iterator){
	--(iterator->data);
	iterator = iterator->next;;
    }
    return *this;
}
Sentence & Sentence::operator=(const Sentence &s1){
    // std::cout << "Sentence assignment operator" << std::endl;
    this->~Sentence();
    // this->head = NULL;
    // this->tail = NULL;
    Node_W * iterator = s1.head;
    if(!iterator){
	head = NULL;
	tail = NULL;
    }
    while(iterator){
	this->append(iterator->data);	
	iterator = iterator->next;
    }
    return *this;
}

void Sentence::append(const Word &w){
    Node_W* node = new Node_W();
    node->data = w;
    if(head == NULL && tail == NULL){
	head = node;
	tail = node;
    }else{
	tail->next = node;
	tail = node;	
    }
}

void Sentence::prepend(const Word &w){
    Node_W* node = new Node_W();
    node->data = w;
    if(head == NULL && tail == NULL){
	head = node;
	tail = node;
    }else{
	node->next = head;
	head = node;
    }
}

void Sentence::show(){
    int i = 0;
    Node_W* iterator = head;    
    while(iterator != nullptr){
	++i;
	if(iterator == tail){
	    iterator->data.show();
	    iterator = iterator->next;   	    
	}else{
	    iterator->data.show();
	    std::cout << " ";
	    iterator = iterator->next;   
	}
    }
}

std::ostream & operator<<(std::ostream & os, const Sentence &s1){
    Node_W* iterator = s1.head;
    while(iterator != nullptr){
	if(iterator == s1.tail){
	    os << iterator->data;
	    iterator = iterator->next;
	}else{
	    os << iterator->data;
	    os << " ";
	    iterator = iterator->next;   
	}
    }
    return os;
}
