#ifndef Sentence_H
#define Sentence_H
#include "Word.h"

class Paragraph;
struct Node_W{
public:
    Word data;
    Node_W * next = NULL;
};
class Sentence{
    /* class NodeW{ */
    /* public: */
    /* 	NodeW * next; */
    /* 	Word val; */
    /* } */
 public:
    Node_W * head = NULL;
    Node_W * tail = NULL;
    void prepend(const Word &w);
    void append(const Word &w);
    Sentence();
    ~Sentence();    
    Sentence(const Sentence &s1);
    Paragraph operator+(const Sentence &s1);
    Paragraph operator+(const Paragraph &p1);
    Sentence operator+(const Word &p1);
    Sentence operator+(const int &i);
    Sentence operator++(int);
    Sentence operator--(int);
    Sentence operator++();
    Sentence operator--();
    Sentence & operator=(const Sentence &s1);
    void show();
    void reinit();
    Word first();
    Sentence rest();
    friend std::ostream & operator<<(std::ostream & os, const Sentence &s1);
};
#endif
