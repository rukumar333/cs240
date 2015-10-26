#include <iostream>
using namespace std;
#include <string>
#include <cstdlib>

#include "TSorter.h"

int main(){
    TSorter<int> s;
    // s.insert(3128937);
    // s.insert(1);
    // s.insert(10);
    // s.insert(-17384);
    for(int i = 0; i < 10; i ++){
	s.insert(rand() % 100);
    }
    // s.show(25, 1);
    s.show(25, 25);
    // s.insertionSortI();
    s.selectionSortI();
    s.show(25, 25);
}
