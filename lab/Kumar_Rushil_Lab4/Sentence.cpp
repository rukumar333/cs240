#include "./Sentence.h"
#include "./Paragraph.h"
#include <iostream>

Sentence::Sentence(){
    std::cout << "Sentence Default constructor" << std::endl;
}

Sentence::~Sentence(){
    std::cout << "Sentence destructor" << std::endl;
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
void Sentence::show(){
    std::cout << "Sentence show used" << std::endl;
}
