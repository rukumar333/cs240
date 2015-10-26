#include <iostream>
using namespace std;
#include <cstdlib>
#include <vector>
template<typename T>
class TSorter{    
 private:
    vector<T> elements;    
 public:    
    TSorter(){
	elements = vector<T>();
    }
    ~TSorter(){
	
    }
    void clear(){
	elements.clear();
    };
    void insert(T value){
	elements.push_back(value);
    };

    template<typename Iterator>
    /* void swap(vector<T>::iterator i, vector<T>::iterator j){ */
    void swap(Iterator i, Iterator j){
	T tmp;
	tmp = *i;
	*i = *j;
	*j = tmp;
	return;
    };

    // Show the first n elements, k per line using << 
    void show(unsigned int limit, unsigned int k){
	int i = 0;
	for(typename vector<T>::iterator it = elements.begin(); it != elements.end() && i < limit; ++it){
	    if(!(i % k)){
		cout << endl;
	    }
	    cout << *it << " ";
	    ++i;
	}
	cout << endl;
    };

    // "Shuffle" the array elements
    void shuffle();

    // These are the functions you should implement for Lab 5
    // You should keep these interfaces the same, but you may add
    // other "helper" functions if necessary.
    void insertionSortI(){
	for(typename vector<T>::iterator it = elements.begin(); it != elements.end(); ++it){
	    bool needToSwap = true;
	    for(typename vector<T>::iterator ik = it; ik != elements.begin() && needToSwap; --ik){
		if(*ik < *(ik - 1)){
		    swap(ik, ik - 1);
		}else{
		    needToSwap = false;
		}
	    }
	}
    }
    void selectionSortI(){
	typename vector<T>::iterator count = elements.end();
	for(typename vector<T>::iterator it = elements.begin(); it != elements.end(); ++it){
	    typename vector<T>::iterator largest = elements.begin();
	    T largestVal = *(elements.begin());
	    for(typename vector<T>::iterator ik = elements.begin(); ik != count - 1; ++ik){
		if(largestVal < *ik){
		    largestVal = *ik;
		    largest = ik;
		}
	    }
	    swap(largest, count - 1);
	    -- count;
	}
    };
    void bubbleSortI();     
    void insertionSortR(); 
    void selectionSortR();	
    void bubbleSortR();

    void insertionForwardR(int i);
    void insertionBackR(int i);

    int selectionGetLargestR(int currentPos, int count, T large, int largeP);
    void selectionInnerR(int currentPos, int count);

    void bubbleOuterR(int currentPos);
    void bubbleInnerR(int currentPos);
};
