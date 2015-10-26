#include <iostream>
using namespace std;

#include "Sorter.h"

void Sorter::swap(int i, int j) {
    int tmp; 
    tmp = array[i]; 
    array[i] = array[j];
    array[j] = tmp; 
    return; 
}

Sorter::Sorter() {
    numElements = 0;
    capacity = 0;
    array = NULL;  
}

Sorter::Sorter(unsigned int initialCapacity) {
    capacity = initialCapacity; 
    numElements = 0;
    array = new int[capacity]; 
}

unsigned int Sorter::makeSpace(unsigned int newCapacity) {
    int *old; 
    unsigned int i;
    if (newCapacity > capacity) {
	old = array; 
	array = new int[newCapacity]; 
	for (i=0; i<numElements; i++) 
	    array[i] = old[i]; 
	capacity = newCapacity;
	delete old; 
    }

    return capacity;
}

void Sorter::clear() {
    numElements = 0;
    return; 
}

bool Sorter::insert(int element) {
    if (numElements >= capacity) 
	return false;
    array[numElements++] = element;  
    return true;
}

Sorter::~Sorter() {
    if (array) {
	delete array; 
	numElements = 0; 
    }
}

// Shuffle array elements
void Sorter::shuffle() {
    unsigned int j; 
    for (unsigned int i=1; i<numElements; i++) {
	j = rand() % i; 
	swap(i, j); 
    }
}

// Show the first n elements, k per line, using << 
void Sorter::show(unsigned int n, unsigned int k) {
    unsigned int toShow = ((n < numElements) ? n : capacity); 
    for (unsigned int i=0; i < toShow; i++) {
	if (!(i%k)) cout << endl;
	cout << array[i] << " "; 
    }
    cout << endl << endl;
} 

// Iterative Snsertion Sort
void Sorter::insertionSortI() {
    for(int i = 0; i < numElements; i ++){
	bool needToSwap = true;
	for(int k = i; k > 0 && needToSwap; k --){
	    if(*(array + k) < *(array + k - 1)){
		swap(k, k - 1);
	    }else{
		needToSwap = false;
	    }
	}
    }
}

// Iterative Selection Sort
void Sorter::selectionSortI() {
    int largest = 0;
    int largestNum = *array;
    int count = numElements;
    for(int i = 0; i < numElements; i ++){
	for(int k = 0; k < count; k ++){
	    if(largestNum < *(array + k)){
		largestNum = *(array + k);
		largest = k;
	    }
	}
	swap(largest, count - 1);
	-- count;
	largestNum = *array;
	largest = 0;
    }
}

// Iterative Bubble Sort
void Sorter::bubbleSortI() {
    int count = numElements;
    for(int i = 0; i < numElements; i ++){
	for(int k = 0; k < count - 1; k ++){
	    if(*(array + k) > *(array + k + 1)){
		swap(k, k + 1);
	    }
	}
    }
}
     
// Recursive Insertion Sort
void Sorter::insertionSortR() {
    insertionForwardR(0);
}

void Sorter::insertionForwardR(int currentPos){
    if(currentPos == numElements){
	return;
    }else{
	insertionBackR(currentPos);
	++ currentPos;
	insertionForwardR(currentPos);
    }
}

void Sorter::insertionBackR(int currentPos){
    if(currentPos == 0){
	return;
    }else{
	if(*(array + currentPos) < *(array + currentPos - 1)){
	    swap(currentPos, currentPos - 1);
	}
	-- currentPos;
	insertionBackR(currentPos);
    }
}

// Recursive Selection Sort
void Sorter::selectionSortR() {
    selectionInnerR(0, numElements);
}

void Sorter::selectionInnerR(int currentPos, int count){
    if(currentPos == numElements){
	return;
    }else{
	int largeP = selectionGetLargestR(0, count, *array, 0);
	swap(largeP, count - 1);
	-- count;
	++ currentPos;
	selectionInnerR(currentPos, count);
    }
}

int Sorter::selectionGetLargestR(int currentPos, int count, int large, int largeP){
    if(currentPos == count){
	return largeP;
    }else{
	if(large < *(array + currentPos)){
	    large = *(array + currentPos);
	    largeP = currentPos;
	}
	currentPos ++;
	return selectionGetLargestR(currentPos, count, large, largeP);
    }
}
	
// Recursive Bubble Sort
void Sorter::bubbleSortR() {
    bubbleOuterR(0);
}

void Sorter::bubbleOuterR(int currentPos){
    if(currentPos == numElements){
	return;
    }else{
	bubbleInnerR(0);
	++ currentPos;
	bubbleOuterR(currentPos);
    }
}

void Sorter::bubbleInnerR(int currentPos){
    if(currentPos == (numElements - 1)){
	return;
    }else{
	if(*(array + currentPos) > *(array + currentPos + 1)){
	    swap(currentPos, currentPos + 1);
	}
	++ currentPos;
	bubbleInnerR(currentPos);
    }
}

