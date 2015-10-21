#include "Paragraph.h"
#include "Story.h"
#include <iostream>

Paragraph::Paragraph(){
    std::cout << "Paragraph Default constructor" << std::endl;
}

Paragraph::~Paragraph(){
    std::cout << "Paragraph destructor" << std::endl;
}    

Paragraph::Paragraph(const Paragraph &p1){
    std::cout << "Paragraph copy constructor" << std::endl;
}

Paragraph Paragraph::operator+(const Sentence &s1){
    std::cout << "Paragraph + Sentence" << std::endl;
}
Paragraph Paragraph::operator+(const Paragraph &p1){
    std::cout << "Paragraph + Paragraph" << std::endl;    
}
Story Paragraph::operator+(const Story &s1){
    std::cout << "Paragraph + Story" << std::endl;        
}
Paragraph Paragraph::operator+(const int &i){
    std::cout << "Paragraph + 1 (all other ints should be ignored)" << std::endl; 
}
Paragraph Paragraph::operator++(int){
    std::cout << "Paragraph++" << std::endl;     
}
Paragraph Paragraph::operator--(int){
    std::cout << "Paragraph--" << std::endl;     
}
Paragraph Paragraph::operator++(){
    std::cout << "++Paragraph" << std::endl;     
}
Paragraph Paragraph::operator--(){
    std::cout << "--Paragraph" << std::endl;     
}
Paragraph & Paragraph::operator=(const Paragraph &p1){
    std::cout << "Paragraph assignment operator" << std::endl;     
}
void Paragraph::show(){
    std::cout << "Paragraph show used" << std::endl;
}

std::ostream & operator<<(std::ostream & os, const Paragraph &p1){
    std::cout << "Bitshift for paragraph used";
    return os;
}
