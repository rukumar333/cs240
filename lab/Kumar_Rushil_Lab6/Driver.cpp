#include "BST.h"
#include <iostream>

int main(){
    BST tree = BST();
    tree.insert(50);
    tree.insert(100);
    tree.insert(1);
    tree.insert(15);
    tree.insert(10);
    tree.insert(33);
    tree.insert(14);
    tree.insert(12);
    tree.insert(45);
    std::cout << tree.height() << std::endl;
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
