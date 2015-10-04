#include "./Word.h"
#include <iostream>

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
