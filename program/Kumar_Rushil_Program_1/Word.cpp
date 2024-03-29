#include "Word.h"
#include "Sentence.h"
#include <iostream>

std::string vowel = "aeiouAEIOU";

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
    // std::cout << "Constructor with char*" << std::endl;
    text = copyArray(word);
}

Word::Word(const Word &w1){
    // std::cout << "Word Copy Constructor" << std::endl;
    text = copyArray(w1.text);
    vowelPigL = w1.vowelPigL;
    consPigL = w1.consPigL;
}

Word::~Word(){
    // std::cout << "Word Destructor" << std::endl;
    if(text != nullptr){
	delete[] text;	
    }
    text = nullptr;
}

Sentence Word::operator+(const Word &w1){
    // std::cout << "Word + Word" << std::endl;
    Sentence s;
    s.append(*this);
    s.append(w1);
    return s;
}

Sentence Word::operator+(const Sentence &s1){
    // std::cout << "Word + Sentence" << std::endl;
    Sentence s = s1;    
    s.prepend(*this);
    return s;
}

Word Word::operator+(const int &i){
    if(text == nullptr){
	return *this;
    }
    if(i == 1){
	if(text != nullptr){
	    *text = toupper(*text);
	}
    }
    return *this;
}

Word Word::operator++(int){
    if(text == nullptr){
	return *this;
    }
    char * iterator = text;
    while(*iterator != '\0' && iterator){
	*iterator = toupper(*iterator);
	++iterator;
    }
    return *this;
}

Word Word::operator--(int){
    if(text == nullptr){
	return *this;
    }
    char * iterator = text;
    while(*iterator != '\0'){
	*iterator = tolower(*iterator);
	++iterator;
    }
    return *this;
}

Word Word::operator++(){
    if(text == nullptr){
	return *this;
    }
    if(vowelPigL || consPigL){
	return *this;
    }
    char * iterator = text;
    int length = 0;
    // bool isUpperCase = false;
    // if(iterator != nullptr){
    // 	isUpperCase = isupper(*iterator);
    // }
    while(*iterator != '\0'){
	++length;
	++iterator;
    }
    iterator = text;
    if(vowel.find(*text) != std::string::npos){
	char * newText = new char[length + 3];
	*(newText + length + 3) = '\0';
	char * newIterator = newText;
	while(*iterator != '\0'){
	    *newIterator = *iterator;
	    ++newIterator;
	    ++iterator;
	}
	*newIterator = 'w';
	++newIterator;
	*newIterator = 'a';
	++newIterator;	
	*newIterator = 'y';
	++newIterator;
	delete[] text;
	text = newText;
	vowelPigL = true;
    }else{
	char * newText = new char[length + 2];
	*(newText + length + 2) = '\0';
	char * newIterator = newText;
	char * firstVowel = nullptr;
	while(*iterator != '\0' && !firstVowel){
	    if(vowel.find(*iterator) != std::string::npos){
		firstVowel = iterator;
	    }
	    ++iterator;
	}
	iterator = text;
	int i = 0;
	while(*(firstVowel + i) != '\0'){
	    *newIterator = *(firstVowel + i);
	    ++i;
	    ++newIterator;
	}
	consPigLIter = newIterator;
	while(iterator != firstVowel){
	    *newIterator = *iterator;
	    ++iterator;
	    ++newIterator;
	}	
	*newIterator = 'a';
	++newIterator;
	*newIterator = 'y';
	delete[] text;
	text = newText;
	consPigL = true;
    }
    return *this;
}

Word Word::operator--(){
    if(text == nullptr){
	return *this;
    }
    if(!vowelPigL && !consPigL){
	return *this;
    }
    char * iterator = text;
    int length = 0;
    while(*iterator != '\0'){
	++length;
	++iterator;
    }
    if(vowelPigL){
	iterator = text;
	char * newText = new char[length - 3];
	char * newIterator = newText;
	*(newText + length - 3) = '\0';
	while(newIterator != newText + length - 3){
	    *newIterator = *iterator;
	    ++newIterator;
	    ++iterator;
	}
	delete[] text;
	text = newText;
    }
    if(consPigL){
	char * newText = new char[length - 2];
	char * newIterator = newText;	
	*(newText + length - 2) = '\0';
	iterator = consPigLIter;
	while(iterator != text + length - 2){
	    *newIterator = *iterator;
	    ++newIterator;
	    ++iterator;
	}
	iterator = text;
	while(newIterator != newText + length - 2){
	    *newIterator = *iterator;
	    ++newIterator;
	    ++iterator;
	}
	delete[] text;
	text = newText;
    }
    return *this;
}

Word & Word::operator=(const Word &w1){
    // std::cout << "Word assignment operator used" << std::endl;
    delete[] text;
    text = copyArray(w1.text);
    vowelPigL = w1.vowelPigL;
    consPigL = w1.consPigL;
}

void Word::setText(char * word){
    text = copyArray(word);
}

char * Word::getText(){
    return text;
}

void Word::show(){
    int i = 0;
    while(text && *(text + i) != '\0'){	
    	std::cout << *(text + i);
    	++i;
    }
    // std::cout << " ";
}

std::ostream & operator<<(std::ostream & os, const Word &w1){
    // std::cout << "Bitshift for word used";
    // int i = 0;
    // char * text = w1.text;
    // while(*(text + i) != '\0'){	
    if(w1.text){
	os << w1.text;
    }
    // }
    return os;
}
