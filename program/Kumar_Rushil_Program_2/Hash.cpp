#include "Hash.h"

Hash::Hash(){
    capacity = 100000;
    arr = new LinkedList[100000];
}

Hash::Hash(int initcap){
    capacity = initcap;
    arr = new LinkedList[capacity];
}

Hash::~Hash(){
    if(arr){
	delete[] arr;	
    }
}

int Hash::hashFunction(Song song){
    std::string data = song.title;
    unsigned long hash = 5381;
    int c = 0;    
    for(unsigned int i = 0; i < data.length(); ++ i){
	c = (int)data[i];
	hash = ((hash << 5) + hash) + (long)c;
    }
    std::cout << "Returning" << std::endl;
    return (int)(hash % (long)capacity);
}

void Hash::insert(Song song, int pos){
    int index = hashFunction(song);
    (arr + index)->append(song, pos);
}

int Hash::getValue(Song song){
    int hash = hashFunction(song);
    LinkedList::Node * iterator = (arr + hash)->head;
    int val = -1;
    while(iterator){
	if(song.title == iterator->song.title && song.artist == iterator->song.artist){
	    val = iterator->data;
	}
    }
    return val;
}
