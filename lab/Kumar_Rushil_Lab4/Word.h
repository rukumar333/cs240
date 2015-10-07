#ifndef Word_H
#define Word_H
#include <iostream>

class Sentence;
class Word{
    char * text;
 public:
    Word();
    Word(char * word);
    Word(const Word &w1);
    ~Word();
    Sentence operator+(const Word &w1);
    Sentence operator+(const Sentence &s1);
    Word operator+(const int &i);
    Word operator++(int);
    Word operator--(int);
    Word operator++();
    Word operator--();
    Word & operator=(const Word &w1);
    char * getText();
    void setText(char * word);
    void show();
};
std::ostream &operator << (std::ostream& os, const Word& w1);
#endif
