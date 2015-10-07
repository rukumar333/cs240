#include "./Story.h"
#include <iostream>

Story::Story(){
    std::cout << "Story Default constructor" << std::endl;
}

Story::~Story(){
    std::cout << "Story destructor" << std::endl;
}    

Story::Story(const Story &s1){
    std::cout << "Story copy constructor" << std::endl;
}

Story Story::operator+(const Story &s1){
    std::cout << "Story + Story" << std::endl;
}
Story Story::operator+(const Paragraph &p1){
    std::cout << "Story + Paragraph" << std::endl;    
}
Story Story::operator+(const int &i){
    std::cout << "Story + 1 (all other ints should be ignored)" << std::endl; 
}
Story Story::operator++(int){
    std::cout << "Story++" << std::endl;     
}
Story Story::operator--(int){
    std::cout << "Story--" << std::endl;     
}
Story Story::operator++(){
    std::cout << "++Story" << std::endl;     
}
Story Story::operator--(){
    std::cout << "--Story" << std::endl;     
}
Story & Story::operator=(const Story &s1){
    std::cout << "Story assignment operator" << std::endl;     
}
void Story::show(){
    std::cout << "Story show used" << std::endl;
}

std::ostream & operator<<(std::ostream & os, const Story &s1){
    std::cout << "Bitshift for story used";
    return os;
}
