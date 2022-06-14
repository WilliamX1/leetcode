#include "BinarySearchTree.h"
#include <iostream>
using namespace std;

template <class KEY, class OTHER> SET<KEY, OTHER> *BinarySearchTree<KEY, OTHER>::find(const KEY &x) const
{
    return find(x, root);
}
template <class KEY, class OTHER> SET<KEY, OTHER> *BinarySearchTree<KEY, OTHER>::find(const KEY &x, BinaryNode *t) const
{
    if (t == NULL || t->data.key == x) //找到或不存在
        return (SET<KEY, OTHER> *)t;
    if (x < t->data.key)
        return find(x, t->left);
    else
        return find(x, t->right);
}
template <class KEY, class OTHER> void BinarySearchTree<KEY, OTHER>::insert(const SET<KEY, OTHER> &x)
{
    insert(x, root);
}
template <class KEY, class OTHER> void BinarySearchTree<KEY, OTHER>::insert(const SET<KEY, OTHER> &x, BinaryNode *&t)
{
    if (t == NULL)
        t = new BinaryNode(x, NULL, NULL);
    else if (x.key < t->data.key)
        insert(x, t->left);
    else if (t->data.key < x.key)
        insert(x, t->right);
}
template <class KEY, class OTHER> void BinarySearchTree<KEY, OTHER>::remove(const KEY &x)
{
    remove(x, root);
}
template <class KEY, class OTHER> void BinarySearchTree<KEY, OTHER>::remove(const KEY &x, BinaryNode *&t)
{
    if (t == NULL)
        return;
    if (x < t->data.key)
        remove(x, t->left);
    else if (t->data.key < x)
        remove(x, t->right);
    else if (t->left != NULL && t->right != NULL) //有两个孩子
    {
        BinaryNode *tmp = t->right;
        while (tmp->left != NULL)
            tmp = tmp->left;
        t->data = tmp->data;
        remove(t->data.key, t->right);
    }
    else
    { //被删结点是叶结点或只有一个孩子
        BinaryNode *oldNode = t;
        t = (t->left != NULL) ? t->left : t->right;
        delete oldNode;
    }
}
template <class KEY, class OTHER> BinarySearchTree<KEY, OTHER>::BinarySearchTree()
{
    root = NULL;
}
template <class KEY, class OTHER> void BinarySearchTree<KEY, OTHER>::makeEmpty(BinaryNode *t)
{
    if (t == NULL)
        return;
    makeEmpty(t->left);
    makeEmpty(t->right);
    delete t;
}
template <class KEY, class OTHER> BinarySearchTree<KEY, OTHER>::~BinarySearchTree()
{
    makeEmpty(root);
}
template class BinarySearchTree<int, const char *>;