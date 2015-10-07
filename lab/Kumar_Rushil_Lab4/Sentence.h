#ifndef Sentence_H
#define Sentence_H
#include "./Word.h"

class Paragraph;
class Sentence{
    /* class NodeW{ */
    /* public: */
    /* 	NodeW * next; */
    /* 	Word val; */
    /* } */
 public:
    Sentence();
    ~Sentence();    
    Sentence(const Sentence &s1);
    Sentence operator+(const Sentence &s1);
    Sentence operator+(const Paragraph &p1);
    Sentence operator+(const Word &p1);
    Sentence operator+(const int &i);
    Sentence operator++(int);
    Sentence operator--(int);
    Sentence operator++();
    Sentence operator--();
    Sentence & operator=(const Sentence &s1);
    void show();
};
std::ostream &operator << (std::ostream& os, const Sentence& s1);
#endif
