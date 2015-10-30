#include "Story.h"
#include <iostream>
#include <fstream>

Story::Story(){
    // std::cout << "Story Default constructor" << std::endl;
}

Story::Story(std::string s){
    std::ifstream file(s);
    std::string input((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    int length = input.length();
    char charArray[length];
    for(unsigned int i = 0; i < length; i ++){
    	charArray[i] = input[i];
    }
    Word word;
    Sentence sentence;
    Paragraph paragraph;
    int i = 0;
    while(charArray[i] != '\0'){
    	char c = charArray[i];
    	// std::cout << i << std::endl;
    	// std::cout << c << std::endl;
	// if(c == '\t'){
	//     std::cout << "TABBED" << std::endl;
	// }
    	// std::cout << +c << std::endl;
    	if(i == 0){
	    if(c == '\t'){
		word = Word(charArray + i + 1);	
	    }else{
		word = Word(charArray + i + 1);		
	    }
    	}else{
    	    if(isspace(c)){
		char next = charArray[i + 1];
		if(next == ' ' || next == '\t' || next == '\n'){
		}else{
		    // std::cout << "SPACED" << std::endl;
		    // std::cout << "SHOWING SENTENCE" << std::endl;
		    // sentence.show();
		    sentence = sentence + word;
		    // std::cout << "SHOWING WORD" << std::endl;
		    // word.show();
		    // std::cout << "SHOWING SENTENCE" << std::endl;
		    // sentence.show();
		    // delete[] word.text;
		    word = Word(charArray + i + 1);   
		}
    	    }
    	    if(c == '.' || c == '!' || c == '?'){
    		sentence = sentence + word;
    		// delete temp;
    		// sentence.append(word);
    		// delete[] word.text;
    		word = Word(charArray + i + 1 + 1);
		++i;
		// std::cout << "PERIOD" << std::endl;
		// sentence.show();
    	    	// paragraph.append(sentence);
		paragraph = paragraph + sentence;
    		sentence.~Sentence();
    		sentence = Sentence();
    	    }
    	    if(c == '\t'){
		// story.append(paragraph);
		*this = *this + paragraph;
		paragraph.~Paragraph();
		paragraph = Paragraph();
    		sentence.~Sentence();
    		sentence = Sentence();
		word = Word(charArray + i + 1);
    	    }
	    if(*(charArray + i + 1) == '\0'){
		// story.append(paragraph);
		*this = *this + paragraph;
		paragraph.~Paragraph();
		paragraph = Paragraph();		
	    }
    	}
    	++i;	
    }        
}

Story::~Story(){
    // std::cout << "Story destructor" << std::endl;
    Node_P * iterator = head;
    Node_P * tempPointer = head;
    while(iterator != nullptr){
    	iterator = iterator->next;
    	delete tempPointer;	
    	tempPointer = iterator;
    }
    head = NULL;
    tail = NULL;
}    

Story::Story(const Story &s1){
    // std::cout << "Story copy constructor" << std::endl;
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
    Story s = *this;
    Node_P * iterator = s1.head;
    while(iterator){
	s.append(iterator->data);
	iterator = iterator->next;
    }
    return s;
}
Story Story::operator+(const Paragraph &p1){
    // std::cout << "Story + Paragraph" << std::endl;
    Story s = *this;
    s.append(p1);
    return s;
}
Story Story::operator+(const int &i){
    if(i != 1){
	return *this;
    }
    Node_P * iterator = head;
    while(iterator){
	(iterator->data) + 1;
	iterator = iterator->next;;
    }
    return *this;    
}
Story Story::operator++(int){
    Node_P * iterator = head;
    while(iterator){
	(iterator->data)++;
	iterator = iterator->next;;
    }
    return *this;    
}
Story Story::operator--(int){
    Node_P * iterator = head;
    while(iterator){
	(iterator->data)--;
	iterator = iterator->next;;
    }
    return *this;    
}
Story Story::operator++(){
    Node_P * iterator = head;
    while(iterator){
	++(iterator->data);
	iterator = iterator->next;;
    }
    return *this;    
}
Story Story::operator--(){
    Node_P * iterator = head;
    while(iterator){
	--(iterator->data);
	iterator = iterator->next;;
    }
    return *this;    
}
Story & Story::operator=(const Story &s1){
    // std::cout << "Story assignment operator" << std::endl;     
    this->~Story();
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
    // std::cout << "APPENDING STORY" << std::endl;
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
    // std::cout << "Story show used" << std::endl;
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

void Story::save(std::string s){
    std::ofstream file(s);
    file << (*this);
}
    // std::cout << "In here" << std::endl;
    // std::cout << "Opened file" << std::endl;
    // std::cout << "Finished" << std::endl;

std::ostream & operator<<(std::ostream & os, const Story &s1){
    Node_P* iterator = s1.head;
    while(iterator != nullptr){
	if(iterator == s1.tail){
	    os << "\t";
	    os << iterator->data;
	    iterator = iterator->next;
	    os << "\n";
	}else{
	    os << "\t";
	    os << iterator->data;
	    os << "\n";
	    iterator = iterator->next;   
	}
    }
    return os;
}
