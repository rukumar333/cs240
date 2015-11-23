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

    void shuffle(){	
	unsigned int j; 
	for (unsigned int i=1; i < elements.size(); i++) {
	    j = rand() % i; 
	    swap(elements.begin() + i, elements.begin() + j); 
	}
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
    void bubbleSortI(){
	typename vector<T>::iterator count = elements.end();
	for(typename vector<T>::iterator it = elements.begin(); it != elements.end(); ++it){
	    for(typename vector<T>::iterator ik = elements.begin(); ik != count - 1; ++ik){
		if(*ik > *(ik + 1)){
		    swap(ik, ik + 1);
		}
	    }
	}
    };

    void insertionSortR(){
	insertionForwardR(elements.begin());
    };

    template<typename Iterator>
    void insertionForwardR(Iterator currentPos){
	if(currentPos == elements.end()){
	    return;
	}else{
	    insertionBackR(currentPos);
	    ++ currentPos;
	    insertionForwardR(currentPos);
	}
    };

    template<typename Iterator>
    void insertionBackR(Iterator currentPos){
	if(currentPos == elements.begin()){
	    return;
	}else{
	    if(*currentPos < *(currentPos - 1)){
		swap(currentPos, currentPos - 1);
	    }
	    -- currentPos;
	    insertionBackR(currentPos);
	}
    };

    void selectionSortR(){
	selectionInnerR(elements.begin(), elements.end());
    };

    template<typename Iterator>
    void selectionInnerR(Iterator currentPos, Iterator count){
	if(currentPos == elements.end()){
	    return;
	}else{
	    typename vector<T>::iterator largeP = selectionGetLargestR(elements.begin(), count, *(elements.begin()), elements.begin());
	    swap(largeP, count - 1);
	    -- count;
	    ++ currentPos;
	    selectionInnerR(currentPos, count);
	}
    };

    template<typename Iterator>
    Iterator selectionGetLargestR(Iterator currentPos, Iterator count, T large, Iterator largeP){
	if(currentPos == count){
	    return largeP;
	}else{
	    if(large < *currentPos){
		large = *currentPos;
		largeP = currentPos;		
	    }
	    ++ currentPos;
	    return selectionGetLargestR(currentPos, count, large, largeP);
	}
    }

    void bubbleSortR(){
	bubbleOuterR(elements.begin());
    };

    template<typename Iterator>
    void bubbleOuterR(Iterator currentPos){
	if(currentPos == elements.end()){
	    return;
	}else{
	    bubbleInnerR(elements.begin());
	    ++ currentPos;
	    bubbleOuterR(currentPos);
	}
    };

    template<typename Iterator>
    void bubbleInnerR(Iterator currentPos){
	if(currentPos == (elements.end() - 1)){
	    return;
	}else{
	    if(*currentPos > *(currentPos + 1)){
		swap(currentPos, currentPos + 1);		
	    }
	    ++ currentPos;
	    bubbleInnerR(currentPos);
	}
    };
    
    void quickSort(){
	quickSortR(elements.begin(), elements.end());
    };
    
    template<typename Iterator>
    void quickSortR(Iterator begin, Iterator end){
	std::cout << "Between " << *begin << " and " << *(end - 1) << std::endl;
	if(begin + 1 == end){
	    return;
	}
	if(begin == end){
	    return;
	}
	Iterator pivot = begin;
	Iterator leftMark = begin + 1;
	Iterator rightMark = end - 1;
	while(leftMark != rightMark){
	    /* std::cout << "In while loop" << std::endl; */
	    if(*leftMark > *pivot){
		swap(leftMark, rightMark);
		-- rightMark;
	    }else{
		++ leftMark;
	    }
	}
	std::cout << "Exited loop" << std::endl;
	show(25, 10);
	if(*leftMark <= *pivot){
	    swap(pivot, leftMark);   
	}
	show(25, 10);
	quickSortR(begin, leftMark);
	quickSortR(leftMark + 1, end);
    };
};
