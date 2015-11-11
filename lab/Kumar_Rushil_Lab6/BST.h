#include <vector>
#include <string>
#include <sstream>

class BST{
 public:
    class BSTNode{
    public:
	int data;
	BSTNode* left = nullptr;
	BSTNode* right = nullptr;
	BSTNode* parent = nullptr;
    };
    int size = 0;
    BSTNode* root = nullptr;
    ~BST();
    void recursiveDelete(BSTNode * node);
    int insert(int val);
    int recursiveInsert(const int& val, BSTNode* node);
    int find(int val);
    int remove(int val);
    int recursiveRemove(int val, BSTNode * node);
    int height();
    int recursiveHeight(BSTNode * current, int height);
    void show();
    void recursiveShow(std::vector<std::string> * output, BSTNode * current, int height);
    /* void recursiveShow(std::array, BSTNode * node); */
    /* void findMax(BSTNode * current); */
};
