#ifndef BINARYTREE_H
#define BINARYTREE_H
#include "bTree.h"
//二叉链表类的定义
template <class T> class binaryTree : public bTree<T>
{
    friend void printTree(const binaryTree<T> &t, T flag);

  private:
    struct Node
    {
        Node *left, *right;
        T data;

        Node() : left(NULL), right(NULL){};
        Node(T item, Node *L = NULL, Node *R = NULL)
        {
            data = item;
            left = L;
            right = R;
        };
        ~Node(){};
    };
    struct StNode
    {
        Node *node;
        int TimesPop;

        StNode(Node *N = NULL) : node(N), TimesPop(0){};
    };

    Node *root; //二叉树的头结点
  public:
    binaryTree() : root(NULL){};
    binaryTree(T x)
    {
        root = new Node(x);
    };
    ~binaryTree();
    void clear();
    bool isEmpty() const;
    T Root(T flag) const;
    T lchild(T x, T flag) const;
    T rchild(T x, T flag) const;
    void delLeft(T x);
    void delRight(T x);
    void preOrder() const;
    void _preOrder() const;
    void midOrder() const;
    void _midOrder() const;
    void postOrder() const;
    void _postOrder() const;
    void levelOrder() const;
    void createTree(T flag);
    int size(Node *t) const;
    int height(Node *t) const;
    T parent(T x, T flag) const;

  private:
    int height() const;
    int size() const;
    Node *find(T x, Node *t) const;
    void clear(Node *&t);
    void preOrder(Node *t) const;
    void midOrder(Node *t) const;
    void postOrder(Node *t) const;
};
#endif // !BINARYTREE_H
