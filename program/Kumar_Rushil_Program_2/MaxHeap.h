#ifndef Heap_H
#define Heap_H
#include <iostream>
#include <math.h>
/* #include <vector> */
#include <string>
#include "Song.h"
#include "Time.h"
#include "Hash.h"
#include "LinkedList.h"

class MaxHeap{
 public:
    MaxHeap();
    //Copy constructor
    MaxHeap(const MaxHeap& other);
    //Destructor
    ~MaxHeap();
    //Assignment operator
    MaxHeap& operator=(const MaxHeap& other);
    Hash hashmap;
    Song *songs;
    Time currentTime;
    int length;
    int capacity;
    void setCapacity(int capacity);
    void insert(Song s);
    Song getMax();
    void pushDown(int pos, int key);
    void pushUp(int pos, int key);
    void swap(int firstPos, int secondPos);
    void like(std::string title);
    void dislike(std::string title);
    /* std::string stringHeap(); */
    /* void recurseString(int height, int pos, std::vector<std::string> * result); */
};

#endif
