#include <iostream>
#include <stdio.h>
#include <string.h>
#include<sstream>
#include <fstream>
#include <iomanip>
using namespace std;

template <class T>
class AVLTreeNode{
    public:
        T key;                // ÃƒÂ¥Ã¢â‚¬Â¦Ã‚Â³ÃƒÂ©Ã¢â‚¬ÂÃ‚Â®ÃƒÂ¥Ã‚Â­Ã¢â‚¬â€(ÃƒÂ©Ã¢â‚¬ÂÃ‚Â®ÃƒÂ¥Ã¢â€šÂ¬Ã‚Â¼)
        int height;         // ÃƒÂ©Ã‚Â«Ã‹Å“ÃƒÂ¥Ã‚ÂºÃ‚Â¦
        AVLTreeNode *left;    // ÃƒÂ¥Ã‚Â·Ã‚Â¦ÃƒÂ¥Ã‚Â­Ã‚Â©ÃƒÂ¥Ã‚Â­Ã‚Â
        AVLTreeNode *right;    // ÃƒÂ¥Ã‚ÂÃ‚Â³ÃƒÂ¥Ã‚Â­Ã‚Â©ÃƒÂ¥Ã‚Â­Ã‚Â

        AVLTreeNode(T value, AVLTreeNode *l, AVLTreeNode *r):
            key(value), height(0),left(l),right(r) {}
};

template <class T>
class AVLTree {
    private:
        AVLTreeNode<T> *mRoot;    // ÃƒÂ¦ Ã‚Â¹ÃƒÂ§Ã‚Â»Ã¢â‚¬Å“ÃƒÂ§Ã¢â‚¬Å¡Ã‚Â¹

    public:
        AVLTree();
        ~AVLTree();

        // ÃƒÂ¨Ã…Â½Ã‚Â·ÃƒÂ¥Ã‚ÂÃ¢â‚¬â€œÃƒÂ¦ Ã¢â‚¬ËœÃƒÂ§Ã…Â¡Ã¢â‚¬Å¾ÃƒÂ©Ã‚Â«Ã‹Å“ÃƒÂ¥Ã‚ÂºÃ‚Â¦
        int height();
        // ÃƒÂ¨Ã…Â½Ã‚Â·ÃƒÂ¥Ã‚ÂÃ¢â‚¬â€œa,bÃƒÂ¤Ã‚Â¸Ã‚Â­ÃƒÂ§Ã…Â¡Ã¢â‚¬Å¾ÃƒÂ¨Ã‚Â¾Ã†â€™ÃƒÂ¥Ã‚Â¤Ã‚Â§ÃƒÂ¥Ã¢â€šÂ¬Ã‚Â¼
        int max(int a, int b);

        // ÃƒÂ¥Ã¢â‚¬Â°Ã‚ÂÃƒÂ¥Ã‚ÂºÃ‚ÂÃƒÂ©Ã‚ÂÃ‚ÂÃƒÂ¥Ã…Â½Ã¢â‚¬ "AVLÃƒÂ¦ Ã¢â‚¬Ëœ"
        void preOrder();
        // ÃƒÂ¤Ã‚Â¸Ã‚Â­ÃƒÂ¥Ã‚ÂºÃ‚ÂÃƒÂ©Ã‚ÂÃ‚ÂÃƒÂ¥Ã…Â½Ã¢â‚¬ "AVLÃƒÂ¦ Ã¢â‚¬Ëœ"
        void inOrder();
        // ÃƒÂ¥Ã‚ÂÃ…Â½ÃƒÂ¥Ã‚ÂºÃ‚ÂÃƒÂ©Ã‚ÂÃ‚ÂÃƒÂ¥Ã…Â½Ã¢â‚¬ "AVLÃƒÂ¦ Ã¢â‚¬Ëœ"
        void postOrder();

        // (ÃƒÂ©Ã¢â€šÂ¬Ã¢â‚¬â„¢ÃƒÂ¥Ã‚Â½Ã¢â‚¬â„¢ÃƒÂ¥Ã‚Â®Ã…Â¾ÃƒÂ§Ã…Â½Ã‚Â°)ÃƒÂ¦Ã…Â¸Ã‚Â¥ÃƒÂ¦Ã¢â‚¬Â°Ã‚Â¾"AVLÃƒÂ¦ Ã¢â‚¬Ëœ"ÃƒÂ¤Ã‚Â¸Ã‚Â­ÃƒÂ©Ã¢â‚¬ÂÃ‚Â®ÃƒÂ¥Ã¢â€šÂ¬Ã‚Â¼ÃƒÂ¤Ã‚Â¸Ã‚ÂºkeyÃƒÂ§Ã…Â¡Ã¢â‚¬Å¾ÃƒÂ¨Ã… Ã¢â‚¬Å¡ÃƒÂ§Ã¢â‚¬Å¡Ã‚Â¹
        AVLTreeNode<T>* search(T key);

        // ÃƒÂ¦Ã…Â¸Ã‚Â¥ÃƒÂ¦Ã¢â‚¬Â°Ã‚Â¾ÃƒÂ¦Ã…â€œÃ¢â€šÂ¬ÃƒÂ¥Ã‚Â°Ã‚ÂÃƒÂ§Ã‚Â»Ã¢â‚¬Å“ÃƒÂ§Ã¢â‚¬Å¡Ã‚Â¹ÃƒÂ¯Ã‚Â¼Ã…Â¡ÃƒÂ¨Ã‚Â¿Ã¢â‚¬ÂÃƒÂ¥Ã¢â‚¬ÂºÃ…Â¾ÃƒÂ¦Ã…â€œÃ¢â€šÂ¬ÃƒÂ¥Ã‚Â°Ã‚ÂÃƒÂ§Ã‚Â»Ã¢â‚¬Å“ÃƒÂ§Ã¢â‚¬Å¡Ã‚Â¹ÃƒÂ§Ã…Â¡Ã¢â‚¬Å¾ÃƒÂ©Ã¢â‚¬ÂÃ‚Â®ÃƒÂ¥Ã¢â€šÂ¬Ã‚Â¼ÃƒÂ£Ã¢â€šÂ¬Ã¢â‚¬Å¡
        T minimum();
        // ÃƒÂ¦Ã…Â¸Ã‚Â¥ÃƒÂ¦Ã¢â‚¬Â°Ã‚Â¾ÃƒÂ¦Ã…â€œÃ¢â€šÂ¬ÃƒÂ¥Ã‚Â¤Ã‚Â§ÃƒÂ§Ã‚Â»Ã¢â‚¬Å“ÃƒÂ§Ã¢â‚¬Å¡Ã‚Â¹ÃƒÂ¯Ã‚Â¼Ã…Â¡ÃƒÂ¨Ã‚Â¿Ã¢â‚¬ÂÃƒÂ¥Ã¢â‚¬ÂºÃ…Â¾ÃƒÂ¦Ã…â€œÃ¢â€šÂ¬ÃƒÂ¥Ã‚Â¤Ã‚Â§ÃƒÂ§Ã‚Â»Ã¢â‚¬Å“ÃƒÂ§Ã¢â‚¬Å¡Ã‚Â¹ÃƒÂ§Ã…Â¡Ã¢â‚¬Å¾ÃƒÂ©Ã¢â‚¬ÂÃ‚Â®ÃƒÂ¥Ã¢â€šÂ¬Ã‚Â¼ÃƒÂ£Ã¢â€šÂ¬Ã¢â‚¬Å¡
        T maximum();

        // ÃƒÂ¥Ã‚Â°Ã¢â‚¬ ÃƒÂ§Ã‚Â»Ã¢â‚¬Å“ÃƒÂ§Ã¢â‚¬Å¡Ã‚Â¹(keyÃƒÂ¤Ã‚Â¸Ã‚ÂºÃƒÂ¨Ã… Ã¢â‚¬Å¡ÃƒÂ§Ã¢â‚¬Å¡Ã‚Â¹ÃƒÂ©Ã¢â‚¬ÂÃ‚Â®ÃƒÂ¥Ã¢â€šÂ¬Ã‚Â¼)ÃƒÂ¦Ã‚ÂÃ¢â‚¬â„¢ÃƒÂ¥Ã¢â‚¬Â¦Ã‚Â¥ÃƒÂ¥Ã‹â€ Ã‚Â°AVLÃƒÂ¦ Ã¢â‚¬ËœÃƒÂ¤Ã‚Â¸Ã‚Â­
        void insert(T key);

        // ÃƒÂ¥Ã‹â€  ÃƒÂ©Ã¢â€žÂ¢Ã‚Â¤ÃƒÂ§Ã‚Â»Ã¢â‚¬Å“ÃƒÂ§Ã¢â‚¬Å¡Ã‚Â¹(keyÃƒÂ¤Ã‚Â¸Ã‚ÂºÃƒÂ¨Ã… Ã¢â‚¬Å¡ÃƒÂ§Ã¢â‚¬Å¡Ã‚Â¹ÃƒÂ©Ã¢â‚¬ÂÃ‚Â®ÃƒÂ¥Ã¢â€šÂ¬Ã‚Â¼)
        void remove(T key);

        // ÃƒÂ©Ã¢â‚¬ÂÃ¢â€šÂ¬ÃƒÂ¦Ã‚Â¯Ã‚ÂAVLÃƒÂ¦ Ã¢â‚¬Ëœ
        void destroy();

    private:
        // ÃƒÂ¨Ã…Â½Ã‚Â·ÃƒÂ¥Ã‚ÂÃ¢â‚¬â€œÃƒÂ¦ Ã¢â‚¬ËœÃƒÂ§Ã…Â¡Ã¢â‚¬Å¾ÃƒÂ©Ã‚Â«Ã‹Å“ÃƒÂ¥Ã‚ÂºÃ‚Â¦
        int height(AVLTreeNode<T>* tree) ;

        // ÃƒÂ¥Ã¢â‚¬Â°Ã‚ÂÃƒÂ¥Ã‚ÂºÃ‚ÂÃƒÂ©Ã‚ÂÃ‚ÂÃƒÂ¥Ã…Â½Ã¢â‚¬ "AVLÃƒÂ¦ Ã¢â‚¬Ëœ"
        void preOrder(AVLTreeNode<T>* tree) const;
        // ÃƒÂ¤Ã‚Â¸Ã‚Â­ÃƒÂ¥Ã‚ÂºÃ‚ÂÃƒÂ©Ã‚ÂÃ‚ÂÃƒÂ¥Ã…Â½Ã¢â‚¬ "AVLÃƒÂ¦ Ã¢â‚¬Ëœ"
        void inOrder(AVLTreeNode<T>* tree) const;
        // ÃƒÂ¥Ã‚ÂÃ…Â½ÃƒÂ¥Ã‚ÂºÃ‚ÂÃƒÂ©Ã‚ÂÃ‚ÂÃƒÂ¥Ã…Â½Ã¢â‚¬ "AVLÃƒÂ¦ Ã¢â‚¬Ëœ"
        void postOrder(AVLTreeNode<T>* tree) const;

        // (ÃƒÂ©Ã¢â€šÂ¬Ã¢â‚¬â„¢ÃƒÂ¥Ã‚Â½Ã¢â‚¬â„¢ÃƒÂ¥Ã‚Â®Ã…Â¾ÃƒÂ§Ã…Â½Ã‚Â°)ÃƒÂ¦Ã…Â¸Ã‚Â¥ÃƒÂ¦Ã¢â‚¬Â°Ã‚Â¾"AVLÃƒÂ¦ Ã¢â‚¬Ëœx"ÃƒÂ¤Ã‚Â¸Ã‚Â­ÃƒÂ©Ã¢â‚¬ÂÃ‚Â®ÃƒÂ¥Ã¢â€šÂ¬Ã‚Â¼ÃƒÂ¤Ã‚Â¸Ã‚ÂºkeyÃƒÂ§Ã…Â¡Ã¢â‚¬Å¾ÃƒÂ¨Ã… Ã¢â‚¬Å¡ÃƒÂ§Ã¢â‚¬Å¡Ã‚Â¹
        AVLTreeNode<T>* search(AVLTreeNode<T>* x, T key) const;

        // ÃƒÂ¦Ã…Â¸Ã‚Â¥ÃƒÂ¦Ã¢â‚¬Â°Ã‚Â¾ÃƒÂ¦Ã…â€œÃ¢â€šÂ¬ÃƒÂ¥Ã‚Â°Ã‚ÂÃƒÂ§Ã‚Â»Ã¢â‚¬Å“ÃƒÂ§Ã¢â‚¬Å¡Ã‚Â¹ÃƒÂ¯Ã‚Â¼Ã…Â¡ÃƒÂ¨Ã‚Â¿Ã¢â‚¬ÂÃƒÂ¥Ã¢â‚¬ÂºÃ…Â¾treeÃƒÂ¤Ã‚Â¸Ã‚ÂºÃƒÂ¦ Ã‚Â¹ÃƒÂ§Ã‚Â»Ã¢â‚¬Å“ÃƒÂ§Ã¢â‚¬Å¡Ã‚Â¹ÃƒÂ§Ã…Â¡Ã¢â‚¬Å¾AVLÃƒÂ¦ Ã¢â‚¬ËœÃƒÂ§Ã…Â¡Ã¢â‚¬Å¾ÃƒÂ¦Ã…â€œÃ¢â€šÂ¬ÃƒÂ¥Ã‚Â°Ã‚ÂÃƒÂ§Ã‚Â»Ã¢â‚¬Å“ÃƒÂ§Ã¢â‚¬Å¡Ã‚Â¹ÃƒÂ£Ã¢â€šÂ¬Ã¢â‚¬Å¡
        AVLTreeNode<T>* minimum(AVLTreeNode<T>* tree);
        // ÃƒÂ¦Ã…Â¸Ã‚Â¥ÃƒÂ¦Ã¢â‚¬Â°Ã‚Â¾ÃƒÂ¦Ã…â€œÃ¢â€šÂ¬ÃƒÂ¥Ã‚Â¤Ã‚Â§ÃƒÂ§Ã‚Â»Ã¢â‚¬Å“ÃƒÂ§Ã¢â‚¬Å¡Ã‚Â¹ÃƒÂ¯Ã‚Â¼Ã…Â¡ÃƒÂ¨Ã‚Â¿Ã¢â‚¬ÂÃƒÂ¥Ã¢â‚¬ÂºÃ…Â¾treeÃƒÂ¤Ã‚Â¸Ã‚ÂºÃƒÂ¦ Ã‚Â¹ÃƒÂ§Ã‚Â»Ã¢â‚¬Å“ÃƒÂ§Ã¢â‚¬Å¡Ã‚Â¹ÃƒÂ§Ã…Â¡Ã¢â‚¬Å¾AVLÃƒÂ¦ Ã¢â‚¬ËœÃƒÂ§Ã…Â¡Ã¢â‚¬Å¾ÃƒÂ¦Ã…â€œÃ¢â€šÂ¬ÃƒÂ¥Ã‚Â¤Ã‚Â§ÃƒÂ§Ã‚Â»Ã¢â‚¬Å“ÃƒÂ§Ã¢â‚¬Å¡Ã‚Â¹ÃƒÂ£Ã¢â€šÂ¬Ã¢â‚¬Å¡
        AVLTreeNode<T>* maximum(AVLTreeNode<T>* tree);

        // LLÃƒÂ¯Ã‚Â¼Ã…Â¡ÃƒÂ¥Ã‚Â·Ã‚Â¦ÃƒÂ¥Ã‚Â·Ã‚Â¦ÃƒÂ¥Ã‚Â¯Ã‚Â¹ÃƒÂ¥Ã‚ÂºÃ¢â‚¬ÂÃƒÂ§Ã…Â¡Ã¢â‚¬Å¾ÃƒÂ¦Ã†â€™Ã¢â‚¬Â¦ÃƒÂ¥Ã¢â‚¬ Ã‚Âµ(ÃƒÂ¥Ã‚Â·Ã‚Â¦ÃƒÂ¥Ã‚ÂÃ¢â‚¬Â¢ÃƒÂ¦Ã¢â‚¬â€Ã¢â‚¬Â¹ÃƒÂ¨Ã‚Â½Ã‚Â¬)ÃƒÂ£Ã¢â€šÂ¬Ã¢â‚¬Å¡
        AVLTreeNode<T>* leftLeftRotation(AVLTreeNode<T>* k2);

        // RRÃƒÂ¯Ã‚Â¼Ã…Â¡ÃƒÂ¥Ã‚ÂÃ‚Â³ÃƒÂ¥Ã‚ÂÃ‚Â³ÃƒÂ¥Ã‚Â¯Ã‚Â¹ÃƒÂ¥Ã‚ÂºÃ¢â‚¬ÂÃƒÂ§Ã…Â¡Ã¢â‚¬Å¾ÃƒÂ¦Ã†â€™Ã¢â‚¬Â¦ÃƒÂ¥Ã¢â‚¬ Ã‚Âµ(ÃƒÂ¥Ã‚ÂÃ‚Â³ÃƒÂ¥Ã‚ÂÃ¢â‚¬Â¢ÃƒÂ¦Ã¢â‚¬â€Ã¢â‚¬Â¹ÃƒÂ¨Ã‚Â½Ã‚Â¬)ÃƒÂ£Ã¢â€šÂ¬Ã¢â‚¬Å¡
        AVLTreeNode<T>* rightRightRotation(AVLTreeNode<T>* k1);

        // LRÃƒÂ¯Ã‚Â¼Ã…Â¡ÃƒÂ¥Ã‚Â·Ã‚Â¦ÃƒÂ¥Ã‚ÂÃ‚Â³ÃƒÂ¥Ã‚Â¯Ã‚Â¹ÃƒÂ¥Ã‚ÂºÃ¢â‚¬ÂÃƒÂ§Ã…Â¡Ã¢â‚¬Å¾ÃƒÂ¦Ã†â€™Ã¢â‚¬Â¦ÃƒÂ¥Ã¢â‚¬ Ã‚Âµ(ÃƒÂ¥Ã‚Â·Ã‚Â¦ÃƒÂ¥Ã‚ÂÃ…â€™ÃƒÂ¦Ã¢â‚¬â€Ã¢â‚¬Â¹ÃƒÂ¨Ã‚Â½Ã‚Â¬)ÃƒÂ£Ã¢â€šÂ¬Ã¢â‚¬Å¡
        AVLTreeNode<T>* leftRightRotation(AVLTreeNode<T>* k3);

        // RLÃƒÂ¯Ã‚Â¼Ã…Â¡ÃƒÂ¥Ã‚ÂÃ‚Â³ÃƒÂ¥Ã‚Â·Ã‚Â¦ÃƒÂ¥Ã‚Â¯Ã‚Â¹ÃƒÂ¥Ã‚ÂºÃ¢â‚¬ÂÃƒÂ§Ã…Â¡Ã¢â‚¬Å¾ÃƒÂ¦Ã†â€™Ã¢â‚¬Â¦ÃƒÂ¥Ã¢â‚¬ Ã‚Âµ(ÃƒÂ¥Ã‚ÂÃ‚Â³ÃƒÂ¥Ã‚ÂÃ…â€™ÃƒÂ¦Ã¢â‚¬â€Ã¢â‚¬Â¹ÃƒÂ¨Ã‚Â½Ã‚Â¬)ÃƒÂ£Ã¢â€šÂ¬Ã¢â‚¬Å¡
        AVLTreeNode<T>* rightLeftRotation(AVLTreeNode<T>* k1);

        // ÃƒÂ¥Ã‚Â°Ã¢â‚¬ ÃƒÂ§Ã‚Â»Ã¢â‚¬Å“ÃƒÂ§Ã¢â‚¬Å¡Ã‚Â¹(z)ÃƒÂ¦Ã‚ÂÃ¢â‚¬â„¢ÃƒÂ¥Ã¢â‚¬Â¦Ã‚Â¥ÃƒÂ¥Ã‹â€ Ã‚Â°AVLÃƒÂ¦ Ã¢â‚¬Ëœ(tree)ÃƒÂ¤Ã‚Â¸Ã‚Â­
        AVLTreeNode<T>* insert(AVLTreeNode<T>* &tree, T key);

        // ÃƒÂ¥Ã‹â€  ÃƒÂ©Ã¢â€žÂ¢Ã‚Â¤AVLÃƒÂ¦ Ã¢â‚¬Ëœ(tree)ÃƒÂ¤Ã‚Â¸Ã‚Â­ÃƒÂ§Ã…Â¡Ã¢â‚¬Å¾ÃƒÂ§Ã‚Â»Ã¢â‚¬Å“ÃƒÂ§Ã¢â‚¬Å¡Ã‚Â¹(z)ÃƒÂ¯Ã‚Â¼Ã…â€™ÃƒÂ¥Ã‚Â¹Ã‚Â¶ÃƒÂ¨Ã‚Â¿Ã¢â‚¬ÂÃƒÂ¥Ã¢â‚¬ÂºÃ…Â¾ÃƒÂ¨Ã‚Â¢Ã‚Â«ÃƒÂ¥Ã‹â€  ÃƒÂ©Ã¢â€žÂ¢Ã‚Â¤ÃƒÂ§Ã…Â¡Ã¢â‚¬Å¾ÃƒÂ§Ã‚Â»Ã¢â‚¬Å“ÃƒÂ§Ã¢â‚¬Å¡Ã‚Â¹
        AVLTreeNode<T>* remove(AVLTreeNode<T>* &tree, AVLTreeNode<T>* z);

        // ÃƒÂ©Ã¢â‚¬ÂÃ¢â€šÂ¬ÃƒÂ¦Ã‚Â¯Ã‚ÂAVLÃƒÂ¦ Ã¢â‚¬Ëœ
        void destroy(AVLTreeNode<T>* &tree);

};

/*
 * ÃƒÂ¦Ã…Â¾Ã¢â‚¬Å¾ÃƒÂ©Ã¢â€šÂ¬ ÃƒÂ¥Ã¢â‚¬Â¡Ã‚Â½ÃƒÂ¦Ã¢â‚¬Â¢Ã‚Â°
 */
template <class T>
AVLTree<T>::AVLTree():mRoot(NULL)
{
}

/*
 * ÃƒÂ¦Ã…Â¾Ã‚ÂÃƒÂ¦Ã…Â¾Ã¢â‚¬Å¾ÃƒÂ¥Ã¢â‚¬Â¡Ã‚Â½ÃƒÂ¦Ã¢â‚¬Â¢Ã‚Â°
 */
template <class T>
AVLTree<T>::~AVLTree()
{
    destroy(mRoot);
}

/*
 * ÃƒÂ¨Ã…Â½Ã‚Â·ÃƒÂ¥Ã‚ÂÃ¢â‚¬â€œÃƒÂ¦ Ã¢â‚¬ËœÃƒÂ§Ã…Â¡Ã¢â‚¬Å¾ÃƒÂ©Ã‚Â«Ã‹Å“ÃƒÂ¥Ã‚ÂºÃ‚Â¦
 */
template <class T>
int AVLTree<T>::height(AVLTreeNode<T>* tree)
{
    if (tree != NULL)
        return tree->height;

    return 0;
}

template <class T>
int AVLTree<T>::height()
{
    return height(mRoot);
}
/*
 * ÃƒÂ¦Ã‚Â¯Ã¢â‚¬ÂÃƒÂ¨Ã‚Â¾Ã†â€™ÃƒÂ¤Ã‚Â¸Ã‚Â¤ÃƒÂ¤Ã‚Â¸Ã‚ÂªÃƒÂ¥Ã¢â€šÂ¬Ã‚Â¼ÃƒÂ§Ã…Â¡Ã¢â‚¬Å¾ÃƒÂ¥Ã‚Â¤Ã‚Â§ÃƒÂ¥Ã‚Â°Ã‚Â
 */
template <class T>
int AVLTree<T>::max(int a, int b)
{
    return a>b ? a : b;
}

/*
 * ÃƒÂ¥Ã¢â‚¬Â°Ã‚ÂÃƒÂ¥Ã‚ÂºÃ‚ÂÃƒÂ©Ã‚ÂÃ‚ÂÃƒÂ¥Ã…Â½Ã¢â‚¬ "AVLÃƒÂ¦ Ã¢â‚¬Ëœ"
 */
template <class T>
void AVLTree<T>::preOrder(AVLTreeNode<T>* tree) const
{
    if(tree != NULL)
    {
        cout<< tree->key << " " ;
        preOrder(tree->left);
        preOrder(tree->right);
    }
}

template <class T>
void AVLTree<T>::preOrder()
{
    preOrder(mRoot);
}

/*
 * ÃƒÂ¤Ã‚Â¸Ã‚Â­ÃƒÂ¥Ã‚ÂºÃ‚ÂÃƒÂ©Ã‚ÂÃ‚ÂÃƒÂ¥Ã…Â½Ã¢â‚¬ "AVLÃƒÂ¦ Ã¢â‚¬Ëœ"
 */
template <class T>
void AVLTree<T>::inOrder(AVLTreeNode<T>* tree) const
{
    if(tree != NULL)
    {
        inOrder(tree->left);
        cout<< tree->key << " " ;
        inOrder(tree->right);
    }
}

template <class T>
void AVLTree<T>::inOrder()
{
    inOrder(mRoot);
}

/*
 * ÃƒÂ¥Ã‚ÂÃ…Â½ÃƒÂ¥Ã‚ÂºÃ‚ÂÃƒÂ©Ã‚ÂÃ‚ÂÃƒÂ¥Ã…Â½Ã¢â‚¬ "AVLÃƒÂ¦ Ã¢â‚¬Ëœ"
 */
template <class T>
void AVLTree<T>::postOrder(AVLTreeNode<T>* tree) const
{
    if(tree != NULL)
    {
        postOrder(tree->left);
        postOrder(tree->right);
        cout<< tree->key << " " ;
    }
}

template <class T>
void AVLTree<T>::postOrder()
{
    postOrder(mRoot);
}

/*
 * (ÃƒÂ©Ã¢â€šÂ¬Ã¢â‚¬â„¢ÃƒÂ¥Ã‚Â½Ã¢â‚¬â„¢ÃƒÂ¥Ã‚Â®Ã…Â¾ÃƒÂ§Ã…Â½Ã‚Â°)ÃƒÂ¦Ã…Â¸Ã‚Â¥ÃƒÂ¦Ã¢â‚¬Â°Ã‚Â¾"AVLÃƒÂ¦ Ã¢â‚¬Ëœx"ÃƒÂ¤Ã‚Â¸Ã‚Â­ÃƒÂ©Ã¢â‚¬ÂÃ‚Â®ÃƒÂ¥Ã¢â€šÂ¬Ã‚Â¼ÃƒÂ¤Ã‚Â¸Ã‚ÂºkeyÃƒÂ§Ã…Â¡Ã¢â‚¬Å¾ÃƒÂ¨Ã… Ã¢â‚¬Å¡ÃƒÂ§Ã¢â‚¬Å¡Ã‚Â¹
 */
template <class T>
AVLTreeNode<T>* AVLTree<T>::search(AVLTreeNode<T>* x, T key) const
{
    if (x==NULL || x->key==key)
        return x;

    if (key < x->key)
        return search(x->left, key);
    else
        return search(x->right, key);
}

template <class T>
AVLTreeNode<T>* AVLTree<T>::search(T key)
{
    return search(mRoot, key);
}

/*
 * ÃƒÂ¦Ã…Â¸Ã‚Â¥ÃƒÂ¦Ã¢â‚¬Â°Ã‚Â¾ÃƒÂ¦Ã…â€œÃ¢â€šÂ¬ÃƒÂ¥Ã‚Â°Ã‚ÂÃƒÂ§Ã‚Â»Ã¢â‚¬Å“ÃƒÂ§Ã¢â‚¬Å¡Ã‚Â¹ÃƒÂ¯Ã‚Â¼Ã…Â¡ÃƒÂ¨Ã‚Â¿Ã¢â‚¬ÂÃƒÂ¥Ã¢â‚¬ÂºÃ…Â¾treeÃƒÂ¤Ã‚Â¸Ã‚ÂºÃƒÂ¦ Ã‚Â¹ÃƒÂ§Ã‚Â»Ã¢â‚¬Å“ÃƒÂ§Ã¢â‚¬Å¡Ã‚Â¹ÃƒÂ§Ã…Â¡Ã¢â‚¬Å¾AVLÃƒÂ¦ Ã¢â‚¬ËœÃƒÂ§Ã…Â¡Ã¢â‚¬Å¾ÃƒÂ¦Ã…â€œÃ¢â€šÂ¬ÃƒÂ¥Ã‚Â°Ã‚ÂÃƒÂ§Ã‚Â»Ã¢â‚¬Å“ÃƒÂ§Ã¢â‚¬Å¡Ã‚Â¹ÃƒÂ£Ã¢â€šÂ¬Ã¢â‚¬Å¡
 */
template <class T>
AVLTreeNode<T>* AVLTree<T>::minimum(AVLTreeNode<T>* tree)
{
    if (tree == NULL)
        return NULL;

    while(tree->left != NULL)
        tree = tree->left;
    return tree;
}

template <class T>
T AVLTree<T>::minimum()
{
    AVLTreeNode<T> *p = minimum(mRoot);
    if (p != NULL)
        return p->key;

    return (T)NULL;
}

/*
 * ÃƒÂ¦Ã…Â¸Ã‚Â¥ÃƒÂ¦Ã¢â‚¬Â°Ã‚Â¾ÃƒÂ¦Ã…â€œÃ¢â€šÂ¬ÃƒÂ¥Ã‚Â¤Ã‚Â§ÃƒÂ§Ã‚Â»Ã¢â‚¬Å“ÃƒÂ§Ã¢â‚¬Å¡Ã‚Â¹ÃƒÂ¯Ã‚Â¼Ã…Â¡ÃƒÂ¨Ã‚Â¿Ã¢â‚¬ÂÃƒÂ¥Ã¢â‚¬ÂºÃ…Â¾treeÃƒÂ¤Ã‚Â¸Ã‚ÂºÃƒÂ¦ Ã‚Â¹ÃƒÂ§Ã‚Â»Ã¢â‚¬Å“ÃƒÂ§Ã¢â‚¬Å¡Ã‚Â¹ÃƒÂ§Ã…Â¡Ã¢â‚¬Å¾AVLÃƒÂ¦ Ã¢â‚¬ËœÃƒÂ§Ã…Â¡Ã¢â‚¬Å¾ÃƒÂ¦Ã…â€œÃ¢â€šÂ¬ÃƒÂ¥Ã‚Â¤Ã‚Â§ÃƒÂ§Ã‚Â»Ã¢â‚¬Å“ÃƒÂ§Ã¢â‚¬Å¡Ã‚Â¹ÃƒÂ£Ã¢â€šÂ¬Ã¢â‚¬Å¡
 */
template <class T>
AVLTreeNode<T>* AVLTree<T>::maximum(AVLTreeNode<T>* tree)
{
    if (tree == NULL)
        return NULL;

    while(tree->right != NULL)
        tree = tree->right;
    return tree;
}

template <class T>
T AVLTree<T>::maximum()
{
    AVLTreeNode<T> *p = maximum(mRoot);
    if (p != NULL)
        return p->key;

    return (T)NULL;
}

/*
 * LLÃƒÂ¯Ã‚Â¼Ã…Â¡ÃƒÂ¥Ã‚Â·Ã‚Â¦ÃƒÂ¥Ã‚Â·Ã‚Â¦ÃƒÂ¥Ã‚Â¯Ã‚Â¹ÃƒÂ¥Ã‚ÂºÃ¢â‚¬ÂÃƒÂ§Ã…Â¡Ã¢â‚¬Å¾ÃƒÂ¦Ã†â€™Ã¢â‚¬Â¦ÃƒÂ¥Ã¢â‚¬ Ã‚Âµ(ÃƒÂ¥Ã‚Â·Ã‚Â¦ÃƒÂ¥Ã‚ÂÃ¢â‚¬Â¢ÃƒÂ¦Ã¢â‚¬â€Ã¢â‚¬Â¹ÃƒÂ¨Ã‚Â½Ã‚Â¬)ÃƒÂ£Ã¢â€šÂ¬Ã¢â‚¬Å¡
 *
 * ÃƒÂ¨Ã‚Â¿Ã¢â‚¬ÂÃƒÂ¥Ã¢â‚¬ÂºÃ…Â¾ÃƒÂ¥Ã¢â€šÂ¬Ã‚Â¼ÃƒÂ¯Ã‚Â¼Ã…Â¡ÃƒÂ¦Ã¢â‚¬â€Ã¢â‚¬Â¹ÃƒÂ¨Ã‚Â½Ã‚Â¬ÃƒÂ¥Ã‚ÂÃ…Â½ÃƒÂ§Ã…Â¡Ã¢â‚¬Å¾ÃƒÂ¦ Ã‚Â¹ÃƒÂ¨Ã… Ã¢â‚¬Å¡ÃƒÂ§Ã¢â‚¬Å¡Ã‚Â¹
 */
template <class T>
AVLTreeNode<T>* AVLTree<T>::leftLeftRotation(AVLTreeNode<T>* k2)
{
    AVLTreeNode<T>* k1;

    k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;

    k2->height = max( height(k2->left), height(k2->right)) + 1;
    k1->height = max( height(k1->left), k2->height) + 1;

    return k1;
}

/*
 * RRÃƒÂ¯Ã‚Â¼Ã…Â¡ÃƒÂ¥Ã‚ÂÃ‚Â³ÃƒÂ¥Ã‚ÂÃ‚Â³ÃƒÂ¥Ã‚Â¯Ã‚Â¹ÃƒÂ¥Ã‚ÂºÃ¢â‚¬ÂÃƒÂ§Ã…Â¡Ã¢â‚¬Å¾ÃƒÂ¦Ã†â€™Ã¢â‚¬Â¦ÃƒÂ¥Ã¢â‚¬ Ã‚Âµ(ÃƒÂ¥Ã‚ÂÃ‚Â³ÃƒÂ¥Ã‚ÂÃ¢â‚¬Â¢ÃƒÂ¦Ã¢â‚¬â€Ã¢â‚¬Â¹ÃƒÂ¨Ã‚Â½Ã‚Â¬)ÃƒÂ£Ã¢â€šÂ¬Ã¢â‚¬Å¡
 *
 * ÃƒÂ¨Ã‚Â¿Ã¢â‚¬ÂÃƒÂ¥Ã¢â‚¬ÂºÃ…Â¾ÃƒÂ¥Ã¢â€šÂ¬Ã‚Â¼ÃƒÂ¯Ã‚Â¼Ã…Â¡ÃƒÂ¦Ã¢â‚¬â€Ã¢â‚¬Â¹ÃƒÂ¨Ã‚Â½Ã‚Â¬ÃƒÂ¥Ã‚ÂÃ…Â½ÃƒÂ§Ã…Â¡Ã¢â‚¬Å¾ÃƒÂ¦ Ã‚Â¹ÃƒÂ¨Ã… Ã¢â‚¬Å¡ÃƒÂ§Ã¢â‚¬Å¡Ã‚Â¹
 */
template <class T>
AVLTreeNode<T>* AVLTree<T>::rightRightRotation(AVLTreeNode<T>* k1)
{
    AVLTreeNode<T>* k2;

    k2 = k1->right;
    k1->right = k2->left;
    k2->left = k1;

    k1->height = max( height(k1->left), height(k1->right)) + 1;
    k2->height = max( height(k2->right), k1->height) + 1;

    return k2;
}

/*
 * LRÃƒÂ¯Ã‚Â¼Ã…Â¡ÃƒÂ¥Ã‚Â·Ã‚Â¦ÃƒÂ¥Ã‚ÂÃ‚Â³ÃƒÂ¥Ã‚Â¯Ã‚Â¹ÃƒÂ¥Ã‚ÂºÃ¢â‚¬ÂÃƒÂ§Ã…Â¡Ã¢â‚¬Å¾ÃƒÂ¦Ã†â€™Ã¢â‚¬Â¦ÃƒÂ¥Ã¢â‚¬ Ã‚Âµ(ÃƒÂ¥Ã‚Â·Ã‚Â¦ÃƒÂ¥Ã‚ÂÃ…â€™ÃƒÂ¦Ã¢â‚¬â€Ã¢â‚¬Â¹ÃƒÂ¨Ã‚Â½Ã‚Â¬)ÃƒÂ£Ã¢â€šÂ¬Ã¢â‚¬Å¡
 *
 * ÃƒÂ¨Ã‚Â¿Ã¢â‚¬ÂÃƒÂ¥Ã¢â‚¬ÂºÃ…Â¾ÃƒÂ¥Ã¢â€šÂ¬Ã‚Â¼ÃƒÂ¯Ã‚Â¼Ã…Â¡ÃƒÂ¦Ã¢â‚¬â€Ã¢â‚¬Â¹ÃƒÂ¨Ã‚Â½Ã‚Â¬ÃƒÂ¥Ã‚ÂÃ…Â½ÃƒÂ§Ã…Â¡Ã¢â‚¬Å¾ÃƒÂ¦ Ã‚Â¹ÃƒÂ¨Ã… Ã¢â‚¬Å¡ÃƒÂ§Ã¢â‚¬Å¡Ã‚Â¹
 */
template <class T>
AVLTreeNode<T>* AVLTree<T>::leftRightRotation(AVLTreeNode<T>* k3)
{
    k3->left = rightRightRotation(k3->left);

    return leftLeftRotation(k3);
}

/*
 * RLÃƒÂ¯Ã‚Â¼Ã…Â¡ÃƒÂ¥Ã‚ÂÃ‚Â³ÃƒÂ¥Ã‚Â·Ã‚Â¦ÃƒÂ¥Ã‚Â¯Ã‚Â¹ÃƒÂ¥Ã‚ÂºÃ¢â‚¬ÂÃƒÂ§Ã…Â¡Ã¢â‚¬Å¾ÃƒÂ¦Ã†â€™Ã¢â‚¬Â¦ÃƒÂ¥Ã¢â‚¬ Ã‚Âµ(ÃƒÂ¥Ã‚ÂÃ‚Â³ÃƒÂ¥Ã‚ÂÃ…â€™ÃƒÂ¦Ã¢â‚¬â€Ã¢â‚¬Â¹ÃƒÂ¨Ã‚Â½Ã‚Â¬)ÃƒÂ£Ã¢â€šÂ¬Ã¢â‚¬Å¡
 */
template <class T>
AVLTreeNode<T>* AVLTree<T>::rightLeftRotation(AVLTreeNode<T>* k1)
{
    k1->right = leftLeftRotation(k1->right);

    return rightRightRotation(k1);
}

/*
 * ÃƒÂ¥Ã‚Â°Ã¢â‚¬ ÃƒÂ§Ã‚Â»Ã¢â‚¬Å“ÃƒÂ§Ã¢â‚¬Å¡Ã‚Â¹ÃƒÂ¦Ã‚ÂÃ¢â‚¬â„¢ÃƒÂ¥Ã¢â‚¬Â¦Ã‚Â¥ÃƒÂ¥Ã‹â€ Ã‚Â°AVLÃƒÂ¦ Ã¢â‚¬ËœÃƒÂ¤Ã‚Â¸Ã‚Â­ÃƒÂ¯Ã‚Â¼Ã…â€™ÃƒÂ¥Ã‚Â¹Ã‚Â¶ÃƒÂ¨Ã‚Â¿Ã¢â‚¬ÂÃƒÂ¥Ã¢â‚¬ÂºÃ…Â¾ÃƒÂ¦ Ã‚Â¹ÃƒÂ¨Ã… Ã¢â‚¬Å¡ÃƒÂ§Ã¢â‚¬Å¡Ã‚Â¹
 */
template <class T>
AVLTreeNode<T>* AVLTree<T>::insert(AVLTreeNode<T>* &tree, T key)
{
    if (tree == NULL)
    {
        // ÃƒÂ¦Ã¢â‚¬â€œÃ‚Â°ÃƒÂ¥Ã‚Â»Ã‚ÂºÃƒÂ¨Ã… Ã¢â‚¬Å¡ÃƒÂ§Ã¢â‚¬Å¡Ã‚Â¹
        tree = new AVLTreeNode<T>(key, NULL, NULL);
        if (tree==NULL)
        {
            return NULL;
        }
    }
    else if (key < tree->key) // ÃƒÂ¥Ã‚ÂºÃ¢â‚¬ÂÃƒÂ¨Ã‚Â¯Ã‚Â¥ÃƒÂ¥Ã‚Â°Ã¢â‚¬ keyÃƒÂ¦Ã‚ÂÃ¢â‚¬â„¢ÃƒÂ¥Ã¢â‚¬Â¦Ã‚Â¥ÃƒÂ¥Ã‹â€ Ã‚Â°"treeÃƒÂ§Ã…Â¡Ã¢â‚¬Å¾ÃƒÂ¥Ã‚Â·Ã‚Â¦ÃƒÂ¥Ã‚Â­Ã‚ÂÃƒÂ¦ Ã¢â‚¬Ëœ"ÃƒÂ§Ã…Â¡Ã¢â‚¬Å¾ÃƒÂ¦Ã†â€™Ã¢â‚¬Â¦ÃƒÂ¥Ã¢â‚¬ Ã‚Âµ
    {
        tree->left = insert(tree->left, key);
        // ÃƒÂ¦Ã‚ÂÃ¢â‚¬â„¢ÃƒÂ¥Ã¢â‚¬Â¦Ã‚Â¥ÃƒÂ¨Ã… Ã¢â‚¬Å¡ÃƒÂ§Ã¢â‚¬Å¡Ã‚Â¹ÃƒÂ¥Ã‚ÂÃ…Â½ÃƒÂ¯Ã‚Â¼Ã…â€™ÃƒÂ¨Ã¢â‚¬Â¹Ã‚Â¥AVLÃƒÂ¦ Ã¢â‚¬ËœÃƒÂ¥Ã‚Â¤Ã‚Â±ÃƒÂ¥Ã…Â½Ã‚Â»ÃƒÂ¥Ã‚Â¹Ã‚Â³ÃƒÂ¨Ã‚Â¡Ã‚Â¡ÃƒÂ¯Ã‚Â¼Ã…â€™ÃƒÂ¥Ã‹â€ Ã¢â€žÂ¢ÃƒÂ¨Ã‚Â¿Ã¢â‚¬ÂºÃƒÂ¨Ã‚Â¡Ã…â€™ÃƒÂ§Ã¢â‚¬ÂºÃ‚Â¸ÃƒÂ¥Ã‚ÂºÃ¢â‚¬ÂÃƒÂ§Ã…Â¡Ã¢â‚¬Å¾ÃƒÂ¨Ã‚Â°Ã†â€™ÃƒÂ¨Ã… Ã¢â‚¬Å¡ÃƒÂ£Ã¢â€šÂ¬Ã¢â‚¬Å¡
        if (height(tree->left) - height(tree->right) == 2)
        {
            if (key < tree->left->key)
                tree = leftLeftRotation(tree);
            else
                tree = leftRightRotation(tree);
        }
    }
    else if (key > tree->key) // ÃƒÂ¥Ã‚ÂºÃ¢â‚¬ÂÃƒÂ¨Ã‚Â¯Ã‚Â¥ÃƒÂ¥Ã‚Â°Ã¢â‚¬ keyÃƒÂ¦Ã‚ÂÃ¢â‚¬â„¢ÃƒÂ¥Ã¢â‚¬Â¦Ã‚Â¥ÃƒÂ¥Ã‹â€ Ã‚Â°"treeÃƒÂ§Ã…Â¡Ã¢â‚¬Å¾ÃƒÂ¥Ã‚ÂÃ‚Â³ÃƒÂ¥Ã‚Â­Ã‚ÂÃƒÂ¦ Ã¢â‚¬Ëœ"ÃƒÂ§Ã…Â¡Ã¢â‚¬Å¾ÃƒÂ¦Ã†â€™Ã¢â‚¬Â¦ÃƒÂ¥Ã¢â‚¬ Ã‚Âµ
    {
        tree->right = insert(tree->right, key);
        // ÃƒÂ¦Ã‚ÂÃ¢â‚¬â„¢ÃƒÂ¥Ã¢â‚¬Â¦Ã‚Â¥ÃƒÂ¨Ã… Ã¢â‚¬Å¡ÃƒÂ§Ã¢â‚¬Å¡Ã‚Â¹ÃƒÂ¥Ã‚ÂÃ…Â½ÃƒÂ¯Ã‚Â¼Ã…â€™ÃƒÂ¨Ã¢â‚¬Â¹Ã‚Â¥AVLÃƒÂ¦ Ã¢â‚¬ËœÃƒÂ¥Ã‚Â¤Ã‚Â±ÃƒÂ¥Ã…Â½Ã‚Â»ÃƒÂ¥Ã‚Â¹Ã‚Â³ÃƒÂ¨Ã‚Â¡Ã‚Â¡ÃƒÂ¯Ã‚Â¼Ã…â€™ÃƒÂ¥Ã‹â€ Ã¢â€žÂ¢ÃƒÂ¨Ã‚Â¿Ã¢â‚¬ÂºÃƒÂ¨Ã‚Â¡Ã…â€™ÃƒÂ§Ã¢â‚¬ÂºÃ‚Â¸ÃƒÂ¥Ã‚ÂºÃ¢â‚¬ÂÃƒÂ§Ã…Â¡Ã¢â‚¬Å¾ÃƒÂ¨Ã‚Â°Ã†â€™ÃƒÂ¨Ã… Ã¢â‚¬Å¡ÃƒÂ£Ã¢â€šÂ¬Ã¢â‚¬Å¡
        if (height(tree->right) - height(tree->left) == 2)
        {
            if (key > tree->right->key)
                tree = rightRightRotation(tree);
            else
                tree = rightLeftRotation(tree);
        }
    }
    tree->height = max( height(tree->left), height(tree->right)) + 1;

    return tree;
}

template <class T>
void AVLTree<T>::insert(T key)
{
    insert(mRoot, key);
}

/*
 * ÃƒÂ¥Ã‹â€  ÃƒÂ©Ã¢â€žÂ¢Ã‚Â¤ÃƒÂ§Ã‚Â»Ã¢â‚¬Å“ÃƒÂ§Ã¢â‚¬Å¡Ã‚Â¹(z)ÃƒÂ¯Ã‚Â¼Ã…â€™ÃƒÂ¨Ã‚Â¿Ã¢â‚¬ÂÃƒÂ¥Ã¢â‚¬ÂºÃ…Â¾ÃƒÂ¦ Ã‚Â¹ÃƒÂ¨Ã… Ã¢â‚¬Å¡ÃƒÂ§Ã¢â‚¬Å¡Ã‚Â¹
 */
template <class T>
AVLTreeNode<T>* AVLTree<T>::remove(AVLTreeNode<T>* &tree, AVLTreeNode<T>* z)
{
    // ÃƒÂ¦ Ã‚Â¹ÃƒÂ¤Ã‚Â¸Ã‚ÂºÃƒÂ§Ã‚Â©Ã‚Âº ÃƒÂ¦Ã‹â€ Ã¢â‚¬â€œÃƒÂ¨Ã¢â€šÂ¬Ã¢â‚¬Â¦ ÃƒÂ¦Ã‚Â²Ã‚Â¡ÃƒÂ¦Ã…â€œÃ¢â‚¬Â°ÃƒÂ¨Ã‚Â¦Ã‚ÂÃƒÂ¥Ã‹â€  ÃƒÂ©Ã¢â€žÂ¢Ã‚Â¤ÃƒÂ§Ã…Â¡Ã¢â‚¬Å¾ÃƒÂ¨Ã… Ã¢â‚¬Å¡ÃƒÂ§Ã¢â‚¬Å¡Ã‚Â¹ÃƒÂ¯Ã‚Â¼Ã…â€™ÃƒÂ§Ã¢â‚¬ÂºÃ‚Â´ÃƒÂ¦Ã…Â½Ã‚Â¥ÃƒÂ¨Ã‚Â¿Ã¢â‚¬ÂÃƒÂ¥Ã¢â‚¬ÂºÃ…Â¾NULLÃƒÂ£Ã¢â€šÂ¬Ã¢â‚¬Å¡
    if (tree==NULL || z==NULL)
        return NULL;

    if (z->key < tree->key)        // ÃƒÂ¥Ã‚Â¾Ã¢â‚¬Â¦ÃƒÂ¥Ã‹â€  ÃƒÂ©Ã¢â€žÂ¢Ã‚Â¤ÃƒÂ§Ã…Â¡Ã¢â‚¬Å¾ÃƒÂ¨Ã… Ã¢â‚¬Å¡ÃƒÂ§Ã¢â‚¬Å¡Ã‚Â¹ÃƒÂ¥Ã…â€œÃ‚Â¨"treeÃƒÂ§Ã…Â¡Ã¢â‚¬Å¾ÃƒÂ¥Ã‚Â·Ã‚Â¦ÃƒÂ¥Ã‚Â­Ã‚ÂÃƒÂ¦ Ã¢â‚¬Ëœ"ÃƒÂ¤Ã‚Â¸Ã‚Â­
    {
        tree->left = remove(tree->left, z);
        // ÃƒÂ¥Ã‹â€  ÃƒÂ©Ã¢â€žÂ¢Ã‚Â¤ÃƒÂ¨Ã… Ã¢â‚¬Å¡ÃƒÂ§Ã¢â‚¬Å¡Ã‚Â¹ÃƒÂ¥Ã‚ÂÃ…Â½ÃƒÂ¯Ã‚Â¼Ã…â€™ÃƒÂ¨Ã¢â‚¬Â¹Ã‚Â¥AVLÃƒÂ¦ Ã¢â‚¬ËœÃƒÂ¥Ã‚Â¤Ã‚Â±ÃƒÂ¥Ã…Â½Ã‚Â»ÃƒÂ¥Ã‚Â¹Ã‚Â³ÃƒÂ¨Ã‚Â¡Ã‚Â¡ÃƒÂ¯Ã‚Â¼Ã…â€™ÃƒÂ¥Ã‹â€ Ã¢â€žÂ¢ÃƒÂ¨Ã‚Â¿Ã¢â‚¬ÂºÃƒÂ¨Ã‚Â¡Ã…â€™ÃƒÂ§Ã¢â‚¬ÂºÃ‚Â¸ÃƒÂ¥Ã‚ÂºÃ¢â‚¬ÂÃƒÂ§Ã…Â¡Ã¢â‚¬Å¾ÃƒÂ¨Ã‚Â°Ã†â€™ÃƒÂ¨Ã… Ã¢â‚¬Å¡ÃƒÂ£Ã¢â€šÂ¬Ã¢â‚¬Å¡
        if (height(tree->right) - height(tree->left) == 2)
        {
            AVLTreeNode<T> *r =  tree->right;
            if (height(r->left) > height(r->right))
                tree = rightLeftRotation(tree);
            else
                tree = rightRightRotation(tree);
        }
    }
    else if (z->key > tree->key)// ÃƒÂ¥Ã‚Â¾Ã¢â‚¬Â¦ÃƒÂ¥Ã‹â€  ÃƒÂ©Ã¢â€žÂ¢Ã‚Â¤ÃƒÂ§Ã…Â¡Ã¢â‚¬Å¾ÃƒÂ¨Ã… Ã¢â‚¬Å¡ÃƒÂ§Ã¢â‚¬Å¡Ã‚Â¹ÃƒÂ¥Ã…â€œÃ‚Â¨"treeÃƒÂ§Ã…Â¡Ã¢â‚¬Å¾ÃƒÂ¥Ã‚ÂÃ‚Â³ÃƒÂ¥Ã‚Â­Ã‚ÂÃƒÂ¦ Ã¢â‚¬Ëœ"ÃƒÂ¤Ã‚Â¸Ã‚Â­
    {
        tree->right = remove(tree->right, z);
        // ÃƒÂ¥Ã‹â€  ÃƒÂ©Ã¢â€žÂ¢Ã‚Â¤ÃƒÂ¨Ã… Ã¢â‚¬Å¡ÃƒÂ§Ã¢â‚¬Å¡Ã‚Â¹ÃƒÂ¥Ã‚ÂÃ…Â½ÃƒÂ¯Ã‚Â¼Ã…â€™ÃƒÂ¨Ã¢â‚¬Â¹Ã‚Â¥AVLÃƒÂ¦ Ã¢â‚¬ËœÃƒÂ¥Ã‚Â¤Ã‚Â±ÃƒÂ¥Ã…Â½Ã‚Â»ÃƒÂ¥Ã‚Â¹Ã‚Â³ÃƒÂ¨Ã‚Â¡Ã‚Â¡ÃƒÂ¯Ã‚Â¼Ã…â€™ÃƒÂ¥Ã‹â€ Ã¢â€žÂ¢ÃƒÂ¨Ã‚Â¿Ã¢â‚¬ÂºÃƒÂ¨Ã‚Â¡Ã…â€™ÃƒÂ§Ã¢â‚¬ÂºÃ‚Â¸ÃƒÂ¥Ã‚ÂºÃ¢â‚¬ÂÃƒÂ§Ã…Â¡Ã¢â‚¬Å¾ÃƒÂ¨Ã‚Â°Ã†â€™ÃƒÂ¨Ã… Ã¢â‚¬Å¡ÃƒÂ£Ã¢â€šÂ¬Ã¢â‚¬Å¡
        if (height(tree->left) - height(tree->right) == 2)
        {
            AVLTreeNode<T> *l =  tree->left;
            if (height(l->right) > height(l->left))
                tree = leftRightRotation(tree);
            else
                tree = leftLeftRotation(tree);
        }
    }
    else    // treeÃƒÂ¦Ã‹Å“Ã‚Â¯ÃƒÂ¥Ã‚Â¯Ã‚Â¹ÃƒÂ¥Ã‚ÂºÃ¢â‚¬ÂÃƒÂ¨Ã‚Â¦Ã‚ÂÃƒÂ¥Ã‹â€  ÃƒÂ©Ã¢â€žÂ¢Ã‚Â¤ÃƒÂ§Ã…Â¡Ã¢â‚¬Å¾ÃƒÂ¨Ã… Ã¢â‚¬Å¡ÃƒÂ§Ã¢â‚¬Å¡Ã‚Â¹ÃƒÂ£Ã¢â€šÂ¬Ã¢â‚¬Å¡
    {
        // treeÃƒÂ§Ã…Â¡Ã¢â‚¬Å¾ÃƒÂ¥Ã‚Â·Ã‚Â¦ÃƒÂ¥Ã‚ÂÃ‚Â³ÃƒÂ¥Ã‚Â­Ã‚Â©ÃƒÂ¥Ã‚Â­Ã‚ÂÃƒÂ©Ã†â€™Ã‚Â½ÃƒÂ©Ã‚ÂÃ…Â¾ÃƒÂ§Ã‚Â©Ã‚Âº
        if ((tree->left!=NULL) && (tree->right!=NULL))
        {
            if (height(tree->left) > height(tree->right))
            {
                // ÃƒÂ¥Ã‚Â¦Ã¢â‚¬Å¡ÃƒÂ¦Ã…Â¾Ã…â€œtreeÃƒÂ§Ã…Â¡Ã¢â‚¬Å¾ÃƒÂ¥Ã‚Â·Ã‚Â¦ÃƒÂ¥Ã‚Â­Ã‚ÂÃƒÂ¦ Ã¢â‚¬ËœÃƒÂ¦Ã‚Â¯Ã¢â‚¬ÂÃƒÂ¥Ã‚ÂÃ‚Â³ÃƒÂ¥Ã‚Â­Ã‚ÂÃƒÂ¦ Ã¢â‚¬ËœÃƒÂ©Ã‚Â«Ã‹Å“ÃƒÂ¯Ã‚Â¼Ã¢â‚¬Âº
                // ÃƒÂ¥Ã‹â€ Ã¢â€žÂ¢(01)ÃƒÂ¦Ã¢â‚¬Â°Ã‚Â¾ÃƒÂ¥Ã¢â‚¬Â¡Ã‚ÂºtreeÃƒÂ§Ã…Â¡Ã¢â‚¬Å¾ÃƒÂ¥Ã‚Â·Ã‚Â¦ÃƒÂ¥Ã‚Â­Ã‚ÂÃƒÂ¦ Ã¢â‚¬ËœÃƒÂ¤Ã‚Â¸Ã‚Â­ÃƒÂ§Ã…Â¡Ã¢â‚¬Å¾ÃƒÂ¦Ã…â€œÃ¢â€šÂ¬ÃƒÂ¥Ã‚Â¤Ã‚Â§ÃƒÂ¨Ã… Ã¢â‚¬Å¡ÃƒÂ§Ã¢â‚¬Å¡Ã‚Â¹
                //   (02)ÃƒÂ¥Ã‚Â°Ã¢â‚¬ ÃƒÂ¨Ã‚Â¯Ã‚Â¥ÃƒÂ¦Ã…â€œÃ¢â€šÂ¬ÃƒÂ¥Ã‚Â¤Ã‚Â§ÃƒÂ¨Ã… Ã¢â‚¬Å¡ÃƒÂ§Ã¢â‚¬Å¡Ã‚Â¹ÃƒÂ§Ã…Â¡Ã¢â‚¬Å¾ÃƒÂ¥Ã¢â€šÂ¬Ã‚Â¼ÃƒÂ¨Ã‚ÂµÃ¢â‚¬Â¹ÃƒÂ¥Ã¢â€šÂ¬Ã‚Â¼ÃƒÂ§Ã‚Â»Ã¢â€žÂ¢treeÃƒÂ£Ã¢â€šÂ¬Ã¢â‚¬Å¡
                //   (03)ÃƒÂ¥Ã‹â€  ÃƒÂ©Ã¢â€žÂ¢Ã‚Â¤ÃƒÂ¨Ã‚Â¯Ã‚Â¥ÃƒÂ¦Ã…â€œÃ¢â€šÂ¬ÃƒÂ¥Ã‚Â¤Ã‚Â§ÃƒÂ¨Ã… Ã¢â‚¬Å¡ÃƒÂ§Ã¢â‚¬Å¡Ã‚Â¹ÃƒÂ£Ã¢â€šÂ¬Ã¢â‚¬Å¡
                // ÃƒÂ¨Ã‚Â¿Ã¢â€žÂ¢ÃƒÂ§Ã‚Â±Ã‚Â»ÃƒÂ¤Ã‚Â¼Ã‚Â¼ÃƒÂ¤Ã‚ÂºÃ…Â½ÃƒÂ§Ã¢â‚¬ÂÃ‚Â¨"treeÃƒÂ§Ã…Â¡Ã¢â‚¬Å¾ÃƒÂ¥Ã‚Â·Ã‚Â¦ÃƒÂ¥Ã‚Â­Ã‚ÂÃƒÂ¦ Ã¢â‚¬ËœÃƒÂ¤Ã‚Â¸Ã‚Â­ÃƒÂ¦Ã…â€œÃ¢â€šÂ¬ÃƒÂ¥Ã‚Â¤Ã‚Â§ÃƒÂ¨Ã… Ã¢â‚¬Å¡ÃƒÂ§Ã¢â‚¬Å¡Ã‚Â¹"ÃƒÂ¥Ã‚ÂÃ…Â¡"tree"ÃƒÂ§Ã…Â¡Ã¢â‚¬Å¾ÃƒÂ¦Ã¢â‚¬ÂºÃ‚Â¿ÃƒÂ¨Ã‚ÂºÃ‚Â«ÃƒÂ¯Ã‚Â¼Ã¢â‚¬Âº
                // ÃƒÂ©Ã¢â‚¬Â¡Ã¢â‚¬Â¡ÃƒÂ§Ã¢â‚¬ÂÃ‚Â¨ÃƒÂ¨Ã‚Â¿Ã¢â€žÂ¢ÃƒÂ§Ã‚Â§Ã‚ÂÃƒÂ¦Ã¢â‚¬â€œÃ‚Â¹ÃƒÂ¥Ã‚Â¼Ã‚ÂÃƒÂ§Ã…Â¡Ã¢â‚¬Å¾ÃƒÂ¥Ã‚Â¥Ã‚Â½ÃƒÂ¥Ã‚Â¤Ã¢â‚¬Å¾ÃƒÂ¦Ã‹Å“Ã‚Â¯ÃƒÂ¯Ã‚Â¼Ã…Â¡ÃƒÂ¥Ã‹â€  ÃƒÂ©Ã¢â€žÂ¢Ã‚Â¤"treeÃƒÂ§Ã…Â¡Ã¢â‚¬Å¾ÃƒÂ¥Ã‚Â·Ã‚Â¦ÃƒÂ¥Ã‚Â­Ã‚ÂÃƒÂ¦ Ã¢â‚¬ËœÃƒÂ¤Ã‚Â¸Ã‚Â­ÃƒÂ¦Ã…â€œÃ¢â€šÂ¬ÃƒÂ¥Ã‚Â¤Ã‚Â§ÃƒÂ¨Ã… Ã¢â‚¬Å¡ÃƒÂ§Ã¢â‚¬Å¡Ã‚Â¹"ÃƒÂ¤Ã‚Â¹Ã¢â‚¬Â¹ÃƒÂ¥Ã‚ÂÃ…Â½ÃƒÂ¯Ã‚Â¼Ã…â€™AVLÃƒÂ¦ Ã¢â‚¬ËœÃƒÂ¤Ã‚Â»Ã‚ÂÃƒÂ§Ã¢â‚¬Å¾Ã‚Â¶ÃƒÂ¦Ã‹Å“Ã‚Â¯ÃƒÂ¥Ã‚Â¹Ã‚Â³ÃƒÂ¨Ã‚Â¡Ã‚Â¡ÃƒÂ§Ã…Â¡Ã¢â‚¬Å¾ÃƒÂ£Ã¢â€šÂ¬Ã¢â‚¬Å¡
                AVLTreeNode<T>* max = maximum(tree->left);
                tree->key = max->key;
                tree->left = remove(tree->left, max);
            }
            else
            {
                // ÃƒÂ¥Ã‚Â¦Ã¢â‚¬Å¡ÃƒÂ¦Ã…Â¾Ã…â€œtreeÃƒÂ§Ã…Â¡Ã¢â‚¬Å¾ÃƒÂ¥Ã‚Â·Ã‚Â¦ÃƒÂ¥Ã‚Â­Ã‚ÂÃƒÂ¦ Ã¢â‚¬ËœÃƒÂ¤Ã‚Â¸Ã‚ÂÃƒÂ¦Ã‚Â¯Ã¢â‚¬ÂÃƒÂ¥Ã‚ÂÃ‚Â³ÃƒÂ¥Ã‚Â­Ã‚ÂÃƒÂ¦ Ã¢â‚¬ËœÃƒÂ©Ã‚Â«Ã‹Å“(ÃƒÂ¥Ã‚ÂÃ‚Â³ÃƒÂ¥Ã‚Â®Ã†â€™ÃƒÂ¤Ã‚Â»Ã‚Â¬ÃƒÂ§Ã¢â‚¬ÂºÃ‚Â¸ÃƒÂ§Ã‚Â­Ã¢â‚¬Â°ÃƒÂ¯Ã‚Â¼Ã…â€™ÃƒÂ¦Ã‹â€ Ã¢â‚¬â€œÃƒÂ¥Ã‚ÂÃ‚Â³ÃƒÂ¥Ã‚Â­Ã‚ÂÃƒÂ¦ Ã¢â‚¬ËœÃƒÂ¦Ã‚Â¯Ã¢â‚¬ÂÃƒÂ¥Ã‚Â·Ã‚Â¦ÃƒÂ¥Ã‚Â­Ã‚ÂÃƒÂ¦ Ã¢â‚¬ËœÃƒÂ©Ã‚Â«Ã‹Å“1)
                // ÃƒÂ¥Ã‹â€ Ã¢â€žÂ¢(01)ÃƒÂ¦Ã¢â‚¬Â°Ã‚Â¾ÃƒÂ¥Ã¢â‚¬Â¡Ã‚ÂºtreeÃƒÂ§Ã…Â¡Ã¢â‚¬Å¾ÃƒÂ¥Ã‚ÂÃ‚Â³ÃƒÂ¥Ã‚Â­Ã‚ÂÃƒÂ¦ Ã¢â‚¬ËœÃƒÂ¤Ã‚Â¸Ã‚Â­ÃƒÂ§Ã…Â¡Ã¢â‚¬Å¾ÃƒÂ¦Ã…â€œÃ¢â€šÂ¬ÃƒÂ¥Ã‚Â°Ã‚ÂÃƒÂ¨Ã… Ã¢â‚¬Å¡ÃƒÂ§Ã¢â‚¬Å¡Ã‚Â¹
                //   (02)ÃƒÂ¥Ã‚Â°Ã¢â‚¬ ÃƒÂ¨Ã‚Â¯Ã‚Â¥ÃƒÂ¦Ã…â€œÃ¢â€šÂ¬ÃƒÂ¥Ã‚Â°Ã‚ÂÃƒÂ¨Ã… Ã¢â‚¬Å¡ÃƒÂ§Ã¢â‚¬Å¡Ã‚Â¹ÃƒÂ§Ã…Â¡Ã¢â‚¬Å¾ÃƒÂ¥Ã¢â€šÂ¬Ã‚Â¼ÃƒÂ¨Ã‚ÂµÃ¢â‚¬Â¹ÃƒÂ¥Ã¢â€šÂ¬Ã‚Â¼ÃƒÂ§Ã‚Â»Ã¢â€žÂ¢treeÃƒÂ£Ã¢â€šÂ¬Ã¢â‚¬Å¡
                //   (03)ÃƒÂ¥Ã‹â€  ÃƒÂ©Ã¢â€žÂ¢Ã‚Â¤ÃƒÂ¨Ã‚Â¯Ã‚Â¥ÃƒÂ¦Ã…â€œÃ¢â€šÂ¬ÃƒÂ¥Ã‚Â°Ã‚ÂÃƒÂ¨Ã… Ã¢â‚¬Å¡ÃƒÂ§Ã¢â‚¬Å¡Ã‚Â¹ÃƒÂ£Ã¢â€šÂ¬Ã¢â‚¬Å¡
                // ÃƒÂ¨Ã‚Â¿Ã¢â€žÂ¢ÃƒÂ§Ã‚Â±Ã‚Â»ÃƒÂ¤Ã‚Â¼Ã‚Â¼ÃƒÂ¤Ã‚ÂºÃ…Â½ÃƒÂ§Ã¢â‚¬ÂÃ‚Â¨"treeÃƒÂ§Ã…Â¡Ã¢â‚¬Å¾ÃƒÂ¥Ã‚ÂÃ‚Â³ÃƒÂ¥Ã‚Â­Ã‚ÂÃƒÂ¦ Ã¢â‚¬ËœÃƒÂ¤Ã‚Â¸Ã‚Â­ÃƒÂ¦Ã…â€œÃ¢â€šÂ¬ÃƒÂ¥Ã‚Â°Ã‚ÂÃƒÂ¨Ã… Ã¢â‚¬Å¡ÃƒÂ§Ã¢â‚¬Å¡Ã‚Â¹"ÃƒÂ¥Ã‚ÂÃ…Â¡"tree"ÃƒÂ§Ã…Â¡Ã¢â‚¬Å¾ÃƒÂ¦Ã¢â‚¬ÂºÃ‚Â¿ÃƒÂ¨Ã‚ÂºÃ‚Â«ÃƒÂ¯Ã‚Â¼Ã¢â‚¬Âº
                // ÃƒÂ©Ã¢â‚¬Â¡Ã¢â‚¬Â¡ÃƒÂ§Ã¢â‚¬ÂÃ‚Â¨ÃƒÂ¨Ã‚Â¿Ã¢â€žÂ¢ÃƒÂ§Ã‚Â§Ã‚ÂÃƒÂ¦Ã¢â‚¬â€œÃ‚Â¹ÃƒÂ¥Ã‚Â¼Ã‚ÂÃƒÂ§Ã…Â¡Ã¢â‚¬Å¾ÃƒÂ¥Ã‚Â¥Ã‚Â½ÃƒÂ¥Ã‚Â¤Ã¢â‚¬Å¾ÃƒÂ¦Ã‹Å“Ã‚Â¯ÃƒÂ¯Ã‚Â¼Ã…Â¡ÃƒÂ¥Ã‹â€  ÃƒÂ©Ã¢â€žÂ¢Ã‚Â¤"treeÃƒÂ§Ã…Â¡Ã¢â‚¬Å¾ÃƒÂ¥Ã‚ÂÃ‚Â³ÃƒÂ¥Ã‚Â­Ã‚ÂÃƒÂ¦ Ã¢â‚¬ËœÃƒÂ¤Ã‚Â¸Ã‚Â­ÃƒÂ¦Ã…â€œÃ¢â€šÂ¬ÃƒÂ¥Ã‚Â°Ã‚ÂÃƒÂ¨Ã… Ã¢â‚¬Å¡ÃƒÂ§Ã¢â‚¬Å¡Ã‚Â¹"ÃƒÂ¤Ã‚Â¹Ã¢â‚¬Â¹ÃƒÂ¥Ã‚ÂÃ…Â½ÃƒÂ¯Ã‚Â¼Ã…â€™AVLÃƒÂ¦ Ã¢â‚¬ËœÃƒÂ¤Ã‚Â»Ã‚ÂÃƒÂ§Ã¢â‚¬Å¾Ã‚Â¶ÃƒÂ¦Ã‹Å“Ã‚Â¯ÃƒÂ¥Ã‚Â¹Ã‚Â³ÃƒÂ¨Ã‚Â¡Ã‚Â¡ÃƒÂ§Ã…Â¡Ã¢â‚¬Å¾ÃƒÂ£Ã¢â€šÂ¬Ã¢â‚¬Å¡
                AVLTreeNode<T>* min = minimum(tree->right);
                tree->key = min->key;
                tree->right = remove(tree->right, min);
            }
        }
        else
        {
            AVLTreeNode<T>* tmp = tree;
            tree = (tree->left!=NULL) ? tree->left : tree->right;
            delete tmp;
        }
    }

    return tree;
}

template <class T>
void AVLTree<T>::remove(T key)
{
    AVLTreeNode<T>* z;

    if ((z = search(mRoot, key)) != NULL)
        mRoot = remove(mRoot, z);
}

/*
 * ÃƒÂ©Ã¢â‚¬ÂÃ¢â€šÂ¬ÃƒÂ¦Ã‚Â¯Ã‚ÂAVLÃƒÂ¦ Ã¢â‚¬Ëœ
 */
template <class T>
void AVLTree<T>::destroy(AVLTreeNode<T>* &tree)
{
    if (tree==NULL)
        return ;

    if (tree->left != NULL)
        destroy(tree->left);
    if (tree->right != NULL)
        destroy(tree->right);

    delete tree;
}

template <class T>
void AVLTree<T>::destroy()
{
    destroy(mRoot);
}

void input() {
    ifstream infile("test.txt");
    string line;
    while(getline(cin, line)) {
        stringstream ss(line);
        // ÃƒÂ¥Ã‹â€ Ã‚ÂÃƒÂ¥Ã‚Â§Ã¢â‚¬Â¹ÃƒÂ¥Ã…â€™Ã¢â‚¬â€œAVLÃƒÂ¦ Ã¢â‚¬Ëœ
        AVLTree<int>* tree=new AVLTree<int>();

        string data;
        while(data != "IN" && data != "POST" && data != "PRE") {

            getline(ss, data, ' ');

            // ÃƒÂ¨Ã‚Â¾Ã¢â‚¬Å“ÃƒÂ¥Ã¢â‚¬Â¡Ã‚ÂºAVLÃƒÂ¦ Ã¢â‚¬Ëœ
            if (data == "IN" || data == "POST" || data == "PRE") {

                // ÃƒÂ¨Ã‚Â¾Ã¢â‚¬Å“ÃƒÂ¥Ã¢â‚¬Â¡Ã‚Âº
                if (!tree->height()) {
                    cout << "EMPTY";
                } else if (data == "IN") {
                    tree->inOrder();
                } else if (data == "POST") {
                    tree->postOrder();
                } else {
                    tree->preOrder();
                }
                tree->destroy();

                // cout << endl;

                break;

            } else {
                string operation = data.substr(0, 1);
                int value = stoi(data.substr(1, data.length() - 1));

                if (operation == "A") {
                    tree->insert(value);
                } else if (operation == "D") {
                    tree->remove(value);
                }
            }

            data = "";
        }

    }
}

int main()
{

    input();
    return 0;
}