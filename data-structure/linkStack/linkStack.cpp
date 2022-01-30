#include "linkStack.h"
#include <iostream>
using namespace std;

template <class elemType>
linkStack<elemType>::linkStack()
{
	top_p = NULL;
}
template <class elemType>
linkStack<elemType>::~linkStack()
{
	node* tmp;
	while (top_p != NULL)
	{
		tmp = top_p;
		top_p = top_p->next;
		delete tmp;
	}
}
template <class elemType>
bool linkStack<elemType>::isEmpty()const
{
	if (top_p == NULL) return true;
	else return false;
}
template <class elemType>
void linkStack<elemType>::push(const elemType& x)
{
	top_p = new node(x, top_p);
}
template <class elemType>
elemType linkStack<elemType>::pop()
{
	node* tmp = top_p;
	elemType x = tmp->data;
	top_p = top_p->next;
	delete tmp;
	return x;
}
template <class elemType>
elemType linkStack<elemType>::top()const
{
	return top_p->data;
}
template class linkStack<int>;
template class linkStack<char>;