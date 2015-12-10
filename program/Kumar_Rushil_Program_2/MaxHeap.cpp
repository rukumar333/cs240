#include "MaxHeap.h"

MaxHeap::MaxHeap(){
    currentTime = Time();
    songs = nullptr;
    capacity = 0;
    length = 0;
}

MaxHeap::MaxHeap(const MaxHeap& other){
    if(songs){
	delete[] songs;
	songs = nullptr;
    }
    currentTime = other.currentTime;
    length = other.length;
    capacity = other.capacity;
    songs = new Song[capacity + 1];
    for(unsigned int i = 0; i < length; ++ i){
	*(songs + i) = *(other.songs + i);
    }
}

MaxHeap::~MaxHeap(){
    std::cout << "Heap Destructor" << std::endl;
    if(songs){
	delete[] songs;	
    }
}

MaxHeap& MaxHeap::operator=(const MaxHeap& other){
    if(songs){
	delete[] songs;
	songs = nullptr;
    }
    currentTime = other.currentTime;
    length = other.length;
    capacity = other.capacity;
    songs = new Song[capacity + 1];
    for(unsigned int i = 0;i < length; ++ i){
	*(songs + i) = *(other.songs + i);
    }
    return *this;
}

void MaxHeap::setCapacity(int capacity){
    this->capacity = capacity;
    if(songs){
	delete[] songs;
	songs = nullptr;
    }    
    songs = new Song[capacity + 1];    
}

void MaxHeap::swap(int firstPos, int secondPos){
    Song temp = *(songs + firstPos);
    *(songs + firstPos) = *(songs + secondPos);
    *(songs + secondPos) = temp;    
}

void MaxHeap::pushUp(int pos, int key){
    if(pos != 1){
	int parentPos = floor(pos / 2);
	int keyParent = (songs + parentPos)->getKey(&currentTime);
	if(keyParent < key){
	    swap(pos, parentPos);
	    pushUp(parentPos, key);
	}
    }
}

void MaxHeap::pushDown(int pos, int key){
    int keyLeft = 0;
    int keyRight = 0;
    int leftPos = pos * 2;
    int rightPos = pos * 2 + 1;
    if(rightPos < length){
	keyLeft = (songs + leftPos)->getKey(&currentTime);
	keyRight = (songs + rightPos)->getKey(&currentTime);
	if(keyLeft > keyRight){
	    if(keyLeft > key){
		swap(pos, leftPos);
		pushDown(leftPos, key);
	    }	    
	}else{
	    if(keyRight > key){
		swap(pos, rightPos);
		pushDown(rightPos, key);
	    }	    
	}
    }else{
	if(leftPos < length){
	    keyLeft = (songs + leftPos)->getKey(&currentTime);
	    if(keyLeft > key){
		swap(pos, leftPos);
		pushDown(leftPos, key);
	    }
	}
    }
}

void MaxHeap::insert(Song s){
    ++ length;
    s.lastPlayed = currentTime;
    int key = (1000 * s.likeability);
    *(songs + length) = s;
    pushUp(length, key);
}

Song MaxHeap::getMax(){
    Song retSong = *(songs + 1);
    currentTime = currentTime + (songs + 1)->length;
    (songs + 1)->lastPlayed = currentTime;
    int key = (songs + 1)->getKey(&currentTime);
    pushDown(1, key);
    return retSong;
}

std::string MaxHeap::stringHeap(){
    // std::vector * result = recurseString(height, 1, "");
    std::vector<std::string> * result = new std::vector<std::string>();
    recurseString(1, 1, result);    
    std::string val = "";
    std::cout << "Capacity: " << capacity << std::endl;
    std::cout << "Length: " << length << std::endl;
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
    std::string key = "";
    if(result->size() < height){
	key = std::to_string((songs + pos)->getKey(&currentTime));
	result->push_back((songs + pos)->stringSong() + " (" + key + ")");
    }else{
	key = std::to_string((songs + pos)->getKey(&currentTime));
	(*result)[height - 1] = (*result)[height - 1] + " || " + (songs + pos)->stringSong() + " (" + key + ")";	
    }
    recurseString(height + 1, pos * 2, result);
    recurseString(height + 1, pos * 2 + 1, result);    
}

