#ifndef Paragraph_H
#define Paragraph_H
#include "Sentence.h"

class Story;
class Paragraph{
    /* class NodeW{ */
    /* public: */
    /* 	NodeW * next; */
    /* 	Word val; */
    /* } */
 public:
    struct Node_S{
    public:
	Sentence data;
	Node_S * next = NULL;
    };
    Node_S * head = NULL;
    Node_S * tail = NULL;
    void prepend(const Sentence &s);
    void append(const Sentence &s);
    Paragraph();
    ~Paragraph();    
    Paragraph(const Paragraph &s1);
    Paragraph operator+(const Paragraph &p1);
    Paragraph operator+(const Sentence &s1);
    Story operator+(const Story &s1);
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
