#include "./Word.h"
#include "./Sentence.h"
#include <iostream>

Word::Word(){
    text = NULL;
}

Word::Word(char * word){
    text = word;
}

Word::Word(const Word &w1){
    text = w1.text;
}

Word::~Word(){
    delete[] text;
}

Word Word::operator+(const Word &w1){
    
}

Word Word::operator+(const Sentence &s1){
    
}

Word Word::operator+(const int &i){
    
}

Word Word::operator++(int){
    
}

Word Word::operator--(int){
    
}

Word Word::operator++(){
    
}

Word Word::operator--(){
    
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
