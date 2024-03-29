#ifndef Hash_H
#define Hash_H

#include "LinkedList.h"
#include "Song.h"
#include "Time.h"

class Hash{
 public:
    Hash();
    /* Hash(int initCap); */
    ~Hash();
    LinkedList * arr;
    int capacity;
    int hashFunction(Song song);
    void insert(Song song, int pos);
    void update(Song song, int pos);
    void setCapacity(int cap);
    int getValue(Song song);    
};

#endif
