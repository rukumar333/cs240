#include "Word.h"
#include "Sentence.h"
#include <iostream>

Word::Word(){
    std::cout << "Word Default Constructor" << std::endl;    
    text = NULL;
}

Word::Word(char * word){
    text = word;
}

Word::Word(const Word &w1){
    std::cout << "Word Copy Constructor" << std::endl;
    int sizeArray = sizeof(w1.text);
    std::cout << sizeArray << std::endl;
    text = new char[sizeArray];
    for(unsigned int i = 0; i < sizeArray; i ++){
	std::cout << text[i];
    	// text[i] = w1.text[i];
    }
    // std::cout << "w";
    delete[] w1.text;
}

Word::~Word(){
    std::cout << "Word Destructor" << std::endl;
    // delete[] text;
}

Sentence Word::operator+(const Word &w1){
    std::cout << "Word + Word" << std::endl;
}

Sentence Word::operator+(const Sentence &s1){
    std::cout << "Word + Sentence" << std::endl;
}

Word Word::operator+(const int &i){
    std::cout << "Word + 1 (all other ints should be ignored)" << std::endl;
}

Word Word::operator++(int){
    std::cout << "Word++" << std::endl;
    return NULL;
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
}

void Word::setText(char * word){
    text = word;
}

char * Word::getText(){
    return text;
}

void Word::show(){
    int i = 0;
    std::cout << "Going to show " << std::endl;
    std::cout << *(text + i) << std::endl;
    while(*(text + i) != '\0'){
    	std::cout << *(text + i);
    	++i;
    }
    std::cout << "Showed" << std::endl;
}

std::ostream & operator<<(std::ostream & os, const Word &w1){
    std::cout << "Bitshift for word used";
    return os;
}
