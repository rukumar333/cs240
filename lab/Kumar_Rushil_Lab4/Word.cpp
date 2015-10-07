#include "./Word.h"
#include "./Sentence.h"
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
    text = w1.text;
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
    std::cout << "Word--" << std::endl;
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
    std::cout << "Text: " << std::endl;
    int i = 0;
    while(*(text + i) != '\0'){
	std::cout << *(text + i);
	++i;
    }
    std::cout << std::endl;
}

std::ostream & operator<<(std::ostream & os, const Word &w1){
    std::cout << "Bitshift for word used" << std::endl;
}
