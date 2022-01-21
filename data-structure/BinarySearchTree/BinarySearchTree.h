#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include "SET.h"
#include "dynamicSearchTable.h"
#include <iostream>
template <class KEY,class OTHER>
class BinarySearchTree :public dynamicSearchTable<KEY, OTHER>
{
private:
	struct BinaryNode
	{
		SET<KEY, OTHER> data;
		BinaryNode* left;
		BinaryNode* right;
		
		BinaryNode(const SET<KEY, OTHER>& thedata, BinaryNode* lt = NULL, BinaryNode* rt = NULL) :
			data(thedata), left(lt), right(rt) {};
	};
	BinaryNode* root;

public:
	BinarySearchTree();
	~BinarySearchTree();
	SET<KEY, OTHER>* find(const KEY& x) const;
	void insert(const SET<KEY, OTHER>& x);
	void remove(const KEY& x);

private:
	void insert(const SET<KEY, OTHER>& x, BinaryNode* &t);
	void remove(const KEY& x, BinaryNode*& t);
	SET<KEY, OTHER>* find(const KEY& x, BinaryNode* t)const;
	void makeEmpty(BinaryNode* t);
};
#endif