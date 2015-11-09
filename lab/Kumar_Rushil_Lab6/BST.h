class BST{
 private:
    
 public:
    struct BSTNode{
	int data;
	BSTNode* left = nullptr;
	BSTNode* right = nullptr;
	BSTNode* parent = nullptr;
    };
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
    void recursiveShow(std::array, BSTNode * node);
    /* void findMax(BSTNode * current); */
};
