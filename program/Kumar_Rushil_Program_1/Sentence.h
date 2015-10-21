#ifndef Sentence_H
#define Sentence_H
#include "Word.h"

class Paragraph;
class Sentence{
    /* class NodeW{ */
    /* public: */
    /* 	NodeW * next; */
    /* 	Word val; */
    /* } */
 public:
    struct Node_W{
    public:
	Word data;
	Node_W * next;
    };
    Node_W * head;
    Node_W * tail;
    void prepend(Word w);
    void append(Word w);
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
};
std::ostream &operator << (std::ostream& os, const Sentence& s1);
#endif
