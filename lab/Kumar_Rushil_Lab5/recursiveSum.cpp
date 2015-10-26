/*
 * Example implementation of direct recursion using
 * an auxiliary function.
 *
 * CS240 Lab 5
 */

#include <iostream> 
using namespace std;

// This would be the public member function of the class
// in your implementation. It is not recursive, but it calls
// its auxiliary function which is recursive.
int sumR();

// The private member function which employs direct recursion
// to compute the sum of an array.
int sumR_aux(int);

// Sum is 34, length of 8
int arr[] = {1, 3, 4, 2, 10, 6, 3, 5};

// Call the direct recursive function from here.
int sumR() {
  // Get the last index of the array
  sumR_aux(sizeof(arr)/sizeof(int) - 1);
}

// The directly recursive function only calls itself.
int sumR_aux(int i) {
  if(i == 0) 
    return arr[i];
  else
    return arr[i] + sumR_aux(i-1);
}

int main() {
  cout << sumR() << endl;
  return 0;
}

/* 
 * The recursive function's execution will end up looking like:
 * sumR()
 * sumR_aux(7)
 * -> sumR_aux(6)
 * --> sumR_aux(5)
 * ---> sumR_aux(4)
 * ----> sumR_aux(3)
 * -----> sumR_aux(2)
 * ------> sumR_aux(1)
 * -------> sumR_aux(0)
 * -------> return arr[0] (1)
 * ------> return arr[1] + arr[0] (4)
 * -----> return arr[2] + arr[1] + arr[0] (8)
 * ----> return arr[3] + arr[2] + arr[1] + arr[0] (10)
 * ---> return arr[4] + arr[3] + arr[2] + arr[1] + arr[0] (20)
 * --> return arr[5] + arr[4] + arr[3] + arr[2] + arr[1] + arr[0] (26)
 * -> return arr[6] + arr[5] + arr[4] + arr[3] + arr[2] + arr[1] + arr[0] (29)
 * return arr[7] + arr[6] + arr[5] + arr[4] + arr[3] + arr[2] + arr[1] + arr[0] (34)
 * return sumR_aux(7)
 *
 * Notice how it is only calling itself. In indirect recursion, your 
 * recursive functions will be calling eachother as they recurse.
 */
