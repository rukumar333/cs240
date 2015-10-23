#include "Sentence.h"
#include "Paragraph.h"
#include <iostream>

Sentence::Sentence(){
    std::cout << "Sentence Default constructor" << std::endl;
    // head = NULL;
    // tail = NULL;
}

Sentence::~Sentence(){
    std::cout << "Sentence destructor" << std::endl;
    Node_W * iterator = head;
    Node_W * tempPointer = head;
    while(iterator != nullptr){
	// iterator->data.~Word();
	std::cout << "Deleting" << std::endl;
	iterator = iterator->next;
	delete tempPointer;	
	tempPointer = iterator;
    }
}    

Sentence::Sentence(const Sentence &s1){
    std::cout << "Sentence copy constructor" << std::endl;
}

Paragraph Sentence::operator+(const Sentence &s1){
    std::cout << "Sentence + Sentence" << std::endl;
}
Paragraph Sentence::operator+(const Paragraph &p1){
    std::cout << "Sentence + Paragraph" << std::endl;    
}
Sentence Sentence::operator+(const Word &p1){
    std::cout << "Sentence + Word" << std::endl;        
}
Sentence Sentence::operator+(const int &i){
    std::cout << "Sentence + 1 (all other ints should be ignored)" << std::endl; 
}
Sentence Sentence::operator++(int){
    std::cout << "Sentence++" << std::endl;     
}
Sentence Sentence::operator--(int){
    std::cout << "Sentence--" << std::endl;     
}
Sentence Sentence::operator++(){
    std::cout << "++Sentence" << std::endl;     
}
Sentence Sentence::operator--(){
    std::cout << "--Sentence" << std::endl;     
}
Sentence & Sentence::operator=(const Sentence &s1){
    std::cout << "Sentence assignment operator" << std::endl;     
}

void Sentence::append(Word w){
    std::cout << "APPENDING" << std::endl;
    
    Node_W* node = new Node_W();
    node->data = w;
    // node->next = NULL;
    if(head == NULL && tail == NULL){
	head = node;
	tail = node;
    }else{
	tail->next = node;
	tail = node;	
    }
    char * iterator = w.getText();
    while(*iterator != '\0'){
	std::cout << *(iterator);
	++iterator;
    }
    std::cout << std::endl << "Leaving appending function" << std::endl;
}

void Sentence::prepend(Word w){
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
    std::cout << "Sentence showing" << std::endl;
    Node_W* iterator = head;    
    while(iterator != nullptr){
	if(iterator == tail){
	    iterator->data.show();
	    std::cout << ". ";
	    iterator = iterator->next;   	    
	}else{
	    iterator->data.show();
	    std::cout << " ";
	    iterator = iterator->next;   
	}
    }
}

std::ostream & operator<<(std::ostream & os, const Sentence &s1){
    std::cout << "Bitshift for Sentence used";
    return os;
}
