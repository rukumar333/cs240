#include "MaxHeap.h"

MaxHeap::MaxHeap(int capacity){
    songs = new Song[capacity + 1];
    length = 0;
}

MaxHeap::MaxHeap(const MaxHeap& other){
    length = other.length;
    capacity = other.capacity;
    songs = new Song[capacity];
    for(unsigned int i = 0; i < length; ++ i){
	*(songs + i) = *(other.songs + i);
    }
}

MaxHeap::~MaxHeap(){
    std::cout << "Heap Destructor" << std::endl;
    delete[] songs;
}

void MaxHeap::swap(int firstPos, int secondPos){
    Song temp = *(songs + firstPos);
    *(songs + firstPos) = *(songs + secondPos);
    *(songs + secondPos) = temp;    
}

void MaxHeap::pushUp(int pos, Time * current, int key){
    if(pos != 1){
	int parentPos = floor(pos / 2);
	int keyParent = (songs + parentPos)->getKey(current);
	if(keyParent < key){
	    swap(pos, parentPos);
	    pushUp(parentPos, current, key);
	}
    }
}

void MaxHeap::pushDown(int pos, Time * current, int key){
    int keyLeft = 0;
    int keyRight = 0;
    int leftPos = pos * 2;
    int rightPos = pos * 2 + 1;
    if(rightPos < length){
	keyLeft = (songs + leftPos)->getKey(current);
	keyRight = (songs + rightPos)->getKey(current);
	if(keyLeft > keyRight){
	    if(keyLeft > key){
		swap(pos, leftPos);
		pushDown(leftPos, current, key);
	    }	    
	}else{
	    if(keyRight > key){
		swap(pos, rightPos);
		pushDown(rightPos, current, key);
	    }	    
	}
    }else{
	if(leftPos < length){
	    keyLeft = (songs + leftPos)->getKey(current);
	    if(keyLeft > key){
		swap(pos, leftPos);
		pushDown(leftPos, current, key);
	    }
	}
    }
}

void MaxHeap::insert(Song s, Time * current){
    ++ length;
    Time t = *current - s.lastPlayed;
    int key = t.getSeconds() + (1000 * s.likeability);
    *(songs + length) = s;
    pushUp(length, current, key);
}

std::string MaxHeap::stringHeap(){
    // std::vector * result = recurseString(height, 1, "");
    std::vector<std::string> * result = new std::vector<std::string>();
    recurseString(1, 1, result);    
    std::string val = "";
    for(unsigned int i = 0; i < result->size(); ++ i){
	val = val + std::to_string(i + 1) + ") " + (*result)[i] + "\n";
    }
    delete result;
    return val;
}

void MaxHeap::recurseString(int height, int pos, std::vector<std::string> * result){
    if(pos > length){
	return;
    }
    if(result->size() < height){
	result->push_back((songs + pos)->stringSong());
    }else{
	(*result)[height - 1] = (*result)[height - 1] + " || " + (songs + pos)->stringSong();	
    }
    recurseString(height + 1, pos * 2, result);
    recurseString(height + 1, pos * 2 + 1, result);    
}

