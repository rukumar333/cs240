#include "Paragraph.h"
#include "Story.h"
#include <iostream>

Paragraph::Paragraph(){
    // std::cout << "Paragraph Default constructor" << std::endl;
}

Paragraph::~Paragraph(){
    // std::cout << "Paragraph destructor" << std::endl;
    Node_S * iterator = head;
    Node_S * tempPointer = head;
    while(iterator != nullptr){
	iterator = iterator->next;
	delete tempPointer;	
	tempPointer = iterator;
    }
    head = NULL;
    tail = NULL;
}    

Paragraph::Paragraph(const Paragraph &p1){
    // std::cout << "Paragraph copy constructor" << std::endl;
    Node_S * iterator = p1.head;
    if(!iterator){
	head = NULL;
	tail = NULL;
    }
    while(iterator != nullptr){
	this->append(iterator->data);
	iterator = iterator->next;
    }
}

Paragraph Paragraph::operator+(const Sentence &s1){
    Paragraph temp = *this;
    temp.append(s1);
    return temp;
}
Paragraph Paragraph::operator+(const Paragraph &p1){
    Paragraph p = *this;
    Node_S * iterator = p1.head;
    while(iterator){
	p.append(iterator->data);
	iterator = iterator->next;
    }
    return p;
}
Story Paragraph::operator+(const Story &s1){
    Story s = s1;
    s.prepend(*this);
    return s;
}
Paragraph Paragraph::operator+(const int &i){
    if(i != 1){
	return *this;
    }
    Node_S * iterator = head;
    while(iterator){
	(iterator->data) + 1;
	iterator = iterator->next;;
    }
    return *this;    
}
Paragraph Paragraph::operator++(int){
    Node_S * iterator = head;
    while(iterator){
	(iterator->data)++;
	iterator = iterator->next;;
    }
    return *this;    
}
Paragraph Paragraph::operator--(int){
    Node_S * iterator = head;
    while(iterator){
	(iterator->data)--;
	iterator = iterator->next;;
    }
    return *this;
}
Paragraph Paragraph::operator++(){
    Node_S * iterator = head;
    while(iterator){
	++(iterator->data);
	iterator = iterator->next;;
    }
    return *this;
}
Paragraph Paragraph::operator--(){
    Node_S * iterator = head;
    while(iterator){
	--(iterator->data);
	iterator = iterator->next;;
    }
    return *this;    
}
Paragraph & Paragraph::operator=(const Paragraph &p1){
    // std::cout << "Paragraph assignment operator" << std::endl;
    this->~Paragraph();
    this->head = NULL;
    this->tail = NULL;
    Node_S * iterator = p1.head;
    if(!iterator){
	head = NULL;
	tail = NULL;
    }
    while(iterator != nullptr){
	this->append(iterator->data);
	iterator = iterator->next;
    }
}

void Paragraph::append(const Sentence &s){
    // std::cout << "APPENDING PARAGRAPH" << std::endl;
    Node_S* node = new Node_S();
    node->data = s;
    if(head == NULL && tail == NULL){
	head = node;
	tail = node;
    }else{
	tail->next = node;
	tail = node;	
    }
}

void Paragraph::prepend(const Sentence &s){
    Node_S* node = new Node_S();
    node->data = s;
    if(head == NULL && tail == NULL){
	head = node;
	tail = node;
    }else{
	node->next = head;
	head = node;
    }    
}

void Paragraph::show(){
    // std::cout << "Paragraph show used" << std::endl;
    Node_S* iterator = head;    
    std::cout << '\t';
    while(iterator != nullptr){
	if(iterator == tail){
	    iterator->data.show();
	    std::cout << '\n';
	    iterator = iterator->next;   	    
	}else{
	    iterator->data.show();
	    std::cout << " ";
	    iterator = iterator->next;   
	}
    }
}

std::ostream & operator<<(std::ostream & os, const Paragraph &p1){
    Node_S* iterator = p1.head;
    while(iterator != nullptr){
	if(iterator == p1.tail){
	    os << iterator->data;
	    os << " ";
	    os << "\n";
	    iterator = iterator->next;   	    
	}else{
	    os << iterator->data;
	    os << " ";
	    iterator = iterator->next;   
	}
    }
    return os;
}
