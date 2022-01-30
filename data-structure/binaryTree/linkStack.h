#pragma once
#ifndef LINKSTACK_H
#define LINKSTACK_H
#include "stack.h"
#include <iostream>
using namespace std;
//栈的链接实现
template <class elemType>
class linkStack :public stack<elemType>
{
private:
	struct node {
		elemType data;
		node* next;
		node(const elemType& x, node* N = NULL)
		{
			data = x; next = N;
		}
		node() :next(NULL) {}
		~node() {}
	};

	node* top_p;
public:
	linkStack();
	~linkStack();
	bool isEmpty()const;
	void push(const elemType& x);
	elemType pop();
	elemType top()const;
};
#endif // !LINKSTACK_H

