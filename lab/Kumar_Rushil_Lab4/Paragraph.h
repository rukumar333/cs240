#ifndef Paragraph_H
#define Paragraph_H
#include "./Sentence.h"

class Story;
class Paragraph{
    /* class NodeW{ */
    /* public: */
    /* 	NodeW * next; */
    /* 	Word val; */
    /* } */
 public:
    Paragraph();
    ~Paragraph();    
    Paragraph(const Paragraph &s1);
    Paragraph operator+(const Paragraph &p1);
    Paragraph operator+(const Sentence &s1);
    Paragraph operator+(const Story &s1);
    Paragraph operator+(const int &i);
    Paragraph operator++(int);
    Paragraph operator--(int);
    Paragraph operator++();
    Paragraph operator--();
    Paragraph & operator=(const Paragraph &p1);
    void show();
};
std::ostream &operator << (std::ostream& os, const Paragraph& p1);
#endif
