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
    MaxHeap();
    MaxHeap(int capacity);    
    //Copy constructor
    MaxHeap(const MaxHeap& other);
    //Destructor
    ~MaxHeap();
    //Assignment operator
    MaxHeap& operator=(const MaxHeap& other);
    Song *songs;
    Time currentTime;
    int length;
    int capacity;
    void insert(Song s);
    Song getMax();
    void pushDown(int pos, int key);
    void pushUp(int pos, int key);
    void swap(int firstPos, int secondPos);
    std::string stringHeap();
    void recurseString(int height, int pos, std::vector<std::string> * result);
};

#endif
