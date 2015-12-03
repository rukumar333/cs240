#ifndef Heap_H
#define Heap_H
#include <iostream>
#include "Song.h"
#include "Time.h"

class MaxHeap{
 public:
    MaxHeap(int capacity);    
    Song *songs;    
    int length;
    void insert();
    Song getMax();
    
};

#endif
