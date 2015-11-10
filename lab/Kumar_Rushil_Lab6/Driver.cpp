#include "BST.h"
#include <iostream>
#include <sys/time.h>

int main(){
    BST tree = BST();
    struct timeval start, finish;
    gettimeofday(&start, NULL);
    for(int i = 0; i < 100000; i++){
	// std::cout << i << std::endl;
	tree.insert(i + 1);
    }
    gettimeofday(&finish, NULL);
    double totalTime = 
	(double)((double)(finish.tv_sec - start.tv_sec) * 1000000 + 
		 (double)(finish.tv_usec - start.tv_usec)) / 
	(double)1000000;
    std::cout << "Time: " << totalTime << " seconds" << std::endl;
    // BST tree = BST();
    // tree.insert(50);
    // tree.insert(100);
    // tree.insert(1);
    // tree.insert(15);
    // tree.insert(10);
    // tree.insert(33);
    // tree.insert(14);
    // tree.insert(12);
    // tree.insert(45);
    // tree.insert(5);
    // tree.insert(8);
    // tree.insert(9);
    // tree.insert(40);
    // tree.remove(50);
    // tree.show();
    // std::cout << tree.height() << std::endl;
    // std::cout << tree.remove(100) << std::endl;
    // std::cout << tree.remove(14) << std::endl;
    // std::cout << tree.remove(45) << std::endl;
    // std::cout << tree.insert(1) << std::endl;
    // //std::cout << "New root: " << tree.root->data << std::endl;
    // std::cout << tree.insert(5) << std::endl;
    // //std::cout << "New root: " << tree.root->data << std::endl;
    // std::cout << tree.insert(100) << std::endl;
    // //std::cout << "New root: " << tree.root->data << std::endl;
    // std::cout << tree.insert(114) << std::endl;
    // //std::cout << "New root: " << tree.root->data << std::endl;
    // std::cout << tree.remove(100) << std::endl;
    // //std::cout << "New root: " << tree.root->data << std::endl;
    // std::cout << tree.remove(1) << std::endl;
    // //std::cout << "New root: " << tree.root->data << std::endl;
    // std::cout << tree.find(5) << std::endl;
    // std::cout << tree.find(1) << std::endl;
    // std::cout << tree.find(100) << std::endl;
    // std::cout << tree.remove(100) << std::endl;
    
    // std::cout << tree.insert(1) << std::endl;
    // std::cout << tree.insert(5) << std::endl;
}
