#include "BST.h"
#include <iostream>
#include <algorithm>
#include <sys/time.h>

void test(int max, bool rand){
    BST tree = BST();
    std::string randString = "";
    if(rand){
	std::vector<int> numbers = std::vector<int>();
	randString = " random ";
	for(int i = 1; i <= max; i++){
	    numbers.push_back(i);
	}
	std::random_shuffle(numbers.begin(), numbers.end());
	for(int i = 0; i <= numbers.size(); i++){
	    tree.insert(numbers[i]);
	}	
    }else{
	randString = " in-order ";
	for(int i = 1; i <= max; i ++){
	    tree.insert(i);
	}	
    }
    struct timeval start, finish;
    double totalTime = 0;
    int i = 1;
    gettimeofday(&start, NULL);
    for(i = 1; i * 10000 <= max; i ++){
	tree.find(i * 10000);
    }
    gettimeofday(&finish, NULL);
    totalTime = 
    	(double)((double)(finish.tv_sec - start.tv_sec) * 1000000 + 
    		 (double)(finish.tv_usec - start.tv_usec)) / 
    	(double)1000000;
    std::cout << "Each find() call on " << max << randString << "node BST takes " << (totalTime / (i - 1)) << " seconds" << std::endl;
    //Removing fours
    for(i = 1; i * 4 <= max; i ++){
	tree.remove(i * 4);
    }
    gettimeofday(&start, NULL);
    for(i = 1; i * 10000 <= max; i ++){
	tree.find(i * 10000);
    }
    gettimeofday(&finish, NULL);
    totalTime = 
    	(double)((double)(finish.tv_sec - start.tv_sec) * 1000000 + 
    		 (double)(finish.tv_usec - start.tv_usec)) / 
    	(double)1000000;
    std::cout << "Each find() call on " << max << randString << "node BST after removing multiples of 4 takes " << (totalTime / (i - 1)) << " seconds" << std::endl;
    //Removing twos
    for(i = 1; i * 2 <= max; i ++){
	tree.remove(i * 2);
    }
    gettimeofday(&start, NULL);
    for(i = 1; i * 10000 <= max; i ++){
	tree.find(i * 10000);
    }
    gettimeofday(&finish, NULL);
    totalTime = 
    	(double)((double)(finish.tv_sec - start.tv_sec) * 1000000 + 
    		 (double)(finish.tv_usec - start.tv_usec)) / 
    	(double)1000000;
    std::cout << "Each find() call on " << max << randString << "node BST after removing multiples of 2 takes " << (totalTime / (i - 1)) << " seconds" << std::endl;
    
}

int main(){
    // test(100000, false);
    // test(100000, true);
    // test(75000, false);
    // test(75000, true);
    // test(20000, false);
    // test(30000, true);
    // test(20000, true);
    // test(10000, false);
    // test(10000, true);
    // test(50000, false);
    // test(50000, true);
    test(1000, true);
    test(1500, true);

    // BST tree = BST();
    // for(int i = 0; i <= 100000; i++){ 
    // 	// std::cout << i << std::endl;
    // 	tree.insert(i + 1);
    // }	
    // std::cout << "Finished inserting" << std::endl;
    // gettimeofday(&start, NULL);
    // // for(int i = 0; i < 10; i ++){9=]
    // // 	tree.find((i + 1) * 10000);
    // // }
    // for(int i = 4; i < 100000; i = i + 4){
    // 	tree.remove(i);
    // }
    // gettimeofday(&finish, NULL);
    // totalTime = 
    // 	(double)((double)(finish.tv_sec - start.tv_sec) * 1000000 + 
    // 		 (double)(finish.tv_usec - start.tv_usec)) / 
    // 	(double)1000000;
    // std::cout << "Each find() call on 100,000 in-order node BST takes " << (totalTime / 10) << " seconds" << std::endl;

    // BST tree1 = BST();
    // std::vector<int> numbers = std::vector<int>();
    // for(int i = 0; i <= 100000; i++){
    // 	numbers.push_back(i + 1);
    // }
    // std::random_shuffle(numbers.begin(), numbers.end());
    // for(int i = 0; i <= 100000; i++){
    // 	tree1.insert(numbers[i]);
    // }
    // // struct timeval start, finish;
    // gettimeofday(&start, NULL);
    // for(int i = 0; i < 10; i ++){
    // 	tree1.find((i + 1) * 10000);
    // }
    // gettimeofday(&finish, NULL);
    // totalTime = 
    // 	(double)((double)(finish.tv_sec - start.tv_sec) * 1000000 + 
    // 		 (double)(finish.tv_usec - start.tv_usec)) / 
    // 	(double)1000000;
    // std::cout << tree1.size << std::endl;
    // std::cout << "Each find() call on 100,000 in-order node BST takes " << (totalTime / 10) << " seconds" << std::endl;

    // for(int i = 4; i <= 100000; i = i + 4){
    // 	tree1.remove(i);
    // }

    // gettimeofday(&start, NULL);
    // for(int i = 0; i < 10; i ++){
    // 	tree1.find((i + 1) * 10000);
    // }
    // gettimeofday(&finish, NULL);
    // totalTime = 
    // 	(double)((double)(finish.tv_sec - start.tv_sec) * 1000000 + 
    // 		 (double)(finish.tv_usec - start.tv_usec)) / 
    // 	(double)1000000;
    // std::cout << tree1.size << std::endl;
    // std::cout << "Each find() call on 100,000 in-order node BST takes " << (totalTime / 10) << " seconds" << std::endl;

    // for(int i = 2; i <= 100000; i = i + 2){
    // 	tree1.remove(i);
    // }

    // gettimeofday(&start, NULL);
    // for(int i = 0; i < 10; i ++){
    // 	tree1.find((i + 1) * 10000);
    // }
    // gettimeofday(&finish, NULL);
    // totalTime = 
    // 	(double)((double)(finish.tv_sec - start.tv_sec) * 1000000 + 
    // 		 (double)(finish.tv_usec - start.tv_usec)) / 
    // 	(double)1000000;
    // std::cout << tree1.size << std::endl;
    // std::cout << "Each find() call on 50,000 in-order node BST takes " << (totalTime / 10) << " seconds" << std::endl;   
}
