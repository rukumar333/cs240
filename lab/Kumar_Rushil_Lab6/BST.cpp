#include <iostream>
#include "BST.h"

BST::~BST(){
    recursiveDelete(root);
}

void BST::recursiveDelete(BSTNode * node){
    if(node != nullptr){
	BSTNode * left = node->left;
	BSTNode * right = node->right;
	delete node;
	recursiveDelete(left);
	recursiveDelete(right);
    }
}

int BST::insert(int val){
    if(root == nullptr){
	root = new BSTNode();
    	root->data = val;
    	return val;
    }    
    recursiveInsert(val, root);
}

int BST::recursiveInsert(const int &val, BSTNode * node){
    // if(node == nullptr){
    // 	node->data = val;
    // 	return val;
    // }
    if(node->data == val){
	return 0;
    }
    if(node->data > val){
	if(node->left == nullptr){
	    node->left = new BSTNode();
	    node->left->data = val;
	    node->left->parent = node;
	    return val;
	}else{
	    return recursiveInsert(val, node->left);   
	}
    }else{
	if(node->right == nullptr){
	    node->right = new BSTNode();
	    node->right->data = val;
	    node->right->parent = node;
	    return val;	    
	}else{
	    return recursiveInsert(val, node->right);
	}
    }
}

int BST::find(int val){
    BSTNode * item = root;
    while(item){
	if(item->data == val){
	    return val;
	}else{
	    if(item->data > val){
		item = item->left;
	    }else{
		item = item->right;
	    }
	}
    }
    return 0;
}

int BST::remove(int val){
    if(root){
	return recursiveRemove(val, root);	
    }else{
	return 0;
    }
}

int BST::recursiveRemove(int val, BSTNode * current){
    //Check if node pointer is null. If so, element was not found.
    if(!current){
	return 0;
    }
    //Case 1: Node is leaf
    if(current->left == nullptr && current->right == nullptr){
	std::cout << "Case 1" << std::endl;
	if(current->data == val){
	    if(current == root){
		delete root;
		root = nullptr;		
		return 1;
	    }
	    if(current == current->parent->left){
		current->parent->left = nullptr;
	    }
	    if(current == current->parent->right){
		current->parent->right = nullptr;
	    }
	    delete current;
	    return 1;
	}
    }
    //Case 2: Node has right subtree
    if(current->left == nullptr && current->right != nullptr){
	std::cout << "Case 2" << std::endl;
	if(current->data == val){
	    if(current == root){
		root = current->right;
		delete current;
		return 1;
	    }
	    if(current == current->parent->left){
		current->parent->left = current->right;
	    }
	    if(current == current->parent->right){
		current->parent->right = current->right;
	    }
	    delete current;
	    return 1;
	}
    }
    //Case 3: Node has left subtree
    if(current->left != nullptr && current->right == nullptr){
	std::cout << "Case 3" << std::endl;
	if(current->data == val){
	    if(current == root){
		root = current->left;
		delete current;
		return 1;
	    }
	    if(current == current->parent->left){
		current->parent->left = current->left;
	    }
	    if(current == current->parent->right){
		current->parent->right = current->left;
	    }
	    delete current;
	    return 1;
	}	
    }
    //Case 4: Node has left subtree and right subtree
    if(current->left != nullptr && current->right != nullptr){
	std::cout << "Case 4" << std::endl;
	if(current->data == val){
	    BSTNode * iterator = current->left;
	    while(iterator->right){
		iterator = iterator->right;
	    }
	    current->data = iterator->data;
	    recursiveRemove(iterator->data, iterator);
	    return 1;
	}
    }
    //Current node does not contain val
    if(current->data > val){
	recursiveRemove(val, current->left);
    }else{
	recursiveRemove(val, current->right);
    }
}

void BST::show(){
    int height = height();
    // std::array<std::string, height> output = std::array<std::string, height>();
    // recursiveShow(output, root);
}

void BST::recursiveShow(std::array<){
    
}

int BST::height(){
    recursiveHeight(root, -1);
}

int BST::recursiveHeight(BSTNode * current, int height){
    if(!current){
	return height;
    }else{
	++height;
	int leftHeight = recursiveHeight(current->left, height);
	int rightHeight = recursiveHeight(current->right, height);
	if(leftHeight > rightHeight){
	    return leftHeight;
	}else{
	    return rightHeight;
	}
    }
    
}
