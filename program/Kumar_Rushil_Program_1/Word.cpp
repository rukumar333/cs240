#include "Word.h"
#include "Sentence.h"
#include <iostream>

char * copyArray(char * input){
    int i = 0;
    int length = 0;
    if(input != nullptr){
	// while(*(input + i) != '\0' && *(input + i) != ' ' && *(input + i) != '.' && *(input + i) != '\t' && *(input + i) != '\n'){
	while(*(input + i) != '\0' && *(input + i) != ' ' && *(input + i) != '\t' && *(input + i) != '\n'){
	    // std::cout << *(input + i) << std::endl;
	    ++length;
	    ++i;
	}	
	char * output = new char[length];
	*(output + i) = '\0';
	i = 0;
	while(i < length){
	    *(output + i) = *(input + i);
	    ++i;
	}	
	return output;
    }else{
	return nullptr;
    }
}

Word::Word(){
    // std::cout << "Word Default Constructor" << std::endl;    
    text = NULL;
}

Word::Word(char * word){
    std::cout << "Constructor with char*" << std::endl;
    text = copyArray(word);
}

Word::Word(const Word &w1){
    std::cout << "Word Copy Constructor" << std::endl;
    text = copyArray(w1.text);    
}

Word::~Word(){
    // std::cout << "Word Destructor" << std::endl;
    if(text != nullptr){
	delete[] text;	
    }
}

Sentence Word::operator+(const Word &w1){
    // std::cout << "Word + Word" << std::endl;
}

Sentence Word::operator+(const Sentence &s1){
    // std::cout << "Word + Sentence" << std::endl;
}

Word Word::operator+(const int &i){
    std::cout << "Word + 1 (all other ints should be ignored)" << std::endl;
}

Word Word::operator++(int){
    std::cout << "Word++" << std::endl;
}

Word Word::operator--(int){
    std::cout << "Word--" << std::endl;    
}

Word Word::operator++(){
    std::cout << "++Word" << std::endl;
}

Word Word::operator--(){
    std::cout << "--Word" << std::endl;
}

Word & Word::operator=(const Word &w1){
    std::cout << "Word assignment operator used" << std::endl;
    text = copyArray(w1.text);
}

void Word::setText(char * word){
    text = copyArray(word);
}

char * Word::getText(){
    return text;
}

void Word::show(){
    int i = 0;
    while(*(text + i) != '\0'){	
    	std::cout << *(text + i);
    	++i;
    }
    // std::cout << " ";
}

std::ostream & operator<<(std::ostream & os, const Word &w1){
    std::cout << "Bitshift for word used";
    return os;
}
