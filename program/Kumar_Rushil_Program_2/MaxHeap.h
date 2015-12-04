#ifndef Heap_H
#define Heap_H
#include <iostream>
#include <math.h>
#include <vector>
#include <string>
#include "Song.h"
#include "Time.h"

class MaxHeap{
 public:
    MaxHeap(int capacity);    
    //Copy constructor
    MaxHeap(const MaxHeap& other);
    //Destructor
    ~MaxHeap();
    Song *songs;    
    int length;
    int capacity;
    void insert(Song s, Time * current);
    Song getMax();
    void pushDown(int pos, Time * current, int key);
    void pushUp(int pos, Time * current, int key);
    void swap(int firstPos, int secondPos);
    std::string stringHeap();
    void recurseString(int height, int pos, std::vector<std::string> * result);
};

#endif
