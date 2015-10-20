#ifndef Story_H
#define Story_H
#include "./Paragraph.h"
class Story{
    /* class NodeW{ */
    /* public: */
    /* 	NodeW * next; */
    /* 	Word val; */
    /* } */
 public:
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
    Story & operator=(const Story &p1);
    void show();
};
std::ostream &operator << (std::ostream& os, const Story& s1);
#endif
