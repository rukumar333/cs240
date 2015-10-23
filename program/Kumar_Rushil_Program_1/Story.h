#ifndef Story_H
#define Story_H
#include "Paragraph.h"
class Story{
    /* class NodeW{ */
    /* public: */
    /* 	NodeW * next; */
    /* 	Word val; */
    /* } */
 public:
    struct Node_P{
	Paragraph data;
	Node_P * next = NULL;
    };
    Node_P * head = NULL;
    Node_P * tail = NULL;
    Story();
    ~Story();    
    Story(const Story &s1);
    Story operator+(const Story &s1);
    Story operator+(const Paragraph &p1);
    Story operator+(const int &i);
    Story operator++(int);
    Story operator--(int);
    Story operator++();
    Story operator--();
    Story & operator=(const Story &s1);
    void append(const Paragraph &p);
    void prepend(const Paragraph &p);
    void show();
};
std::ostream &operator << (std::ostream& os, const Story& s1);
#endif
