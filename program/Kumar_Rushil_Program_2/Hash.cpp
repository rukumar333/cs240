#include "Hash.h"

Hash::Hash(){
    capacity = 0;
    // arr = new LinkedList[100000];
    arr = nullptr;
}

// Hash::Hash(int initcap){
//     capacity = initcap;
//     arr = new LinkedList[capacity];
// }

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
    return (int)(hash % (unsigned long)capacity);
}

void Hash::insert(Song song, int pos){
    int index = hashFunction(song);
    (arr + index)->append(song, pos);
}

void Hash::update(Song song, int pos){
    int hash = hashFunction(song);
    LinkedList::Node * iterator = (arr + hash)->head;
    while(iterator){
	if(song.title == iterator->song.title && song.artist == iterator->song.artist){
	    iterator->data = pos;
	}
	iterator = iterator->next;
    }    
}

void Hash::setCapacity(int cap){
    capacity = cap;
    arr = new LinkedList[cap];
}

int Hash::getValue(Song song){
    int hash = hashFunction(song);
    LinkedList::Node * iterator = (arr + hash)->head;
    int val = -1;
    while(iterator){
	if(song.title == iterator->song.title && song.artist == iterator->song.artist){
	    val = iterator->data;
	}
	iterator = iterator->next;
    }
    return val;
}
