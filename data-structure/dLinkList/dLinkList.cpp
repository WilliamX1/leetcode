#include "dLinkList.h"
#include <iostream>
using namespace std;

template <class elemType> typename dLinkList<elemType>::node *dLinkList<elemType>::move(int i) const
{
    int index = i;
    if (i < currentLength / 2)
    {
        node *pos = head;
        for (int i = 0; i < index; ++i)
            pos = pos->next;
        return pos;
    }
    else
    {
        node *pos = tail;
        for (int i = currentLength; i > index; --i)
            pos = pos->prev;
        return pos;
    }
}
template <class elemType> dLinkList<elemType>::dLinkList()
{
    head = new node;
    tail = new node;
    currentLength = 0;
}
template <class elemType> void dLinkList<elemType>::clear()
{
    node *pos = head->next;
    while (pos != NULL)
    {
        delete pos;
        pos = pos->next;
    }
    currentLength = 0;
}
template <class elemType> void dLinkList<elemType>::insert(int i, const elemType &x)
{
    node *pos = new node;
    pos = move(i);
    node *q = new node(x, pos->prev, pos);
    pos->prev->next = q;
    pos->prev = q;
    ++currentLength;
}
template <class elemType> void dLinkList<elemType>::remove(int i)
{
    node *p = new node;
    p = move(i);
    p->prev->next = p->next;
    p->next->prev = p->prev;
    delete p;
    ++currentLength;
}
template <class elemType> int dLinkList<elemType>::search(const elemType &x) const
{
    int i = 0;
    node *p = head->next;
    while (p->data != x && p != NULL)
    {
        p = p->next;
        ++i;
    }
    if (p == NULL)
        return -1;
    else
        return i;
}
template <class elemType> elemType dLinkList<elemType>::visit(int i) const
{
    node *p = new node;
    p = move(i);
    return p->data;
}
template <class elemType> void dLinkList<elemType>::traverse() const
{
    node *p = head->next;
    cout << endl;
    while (p != tail)
    {
        cout << p->data << " ";
        p = p->next;
    }
}
template class dLinkList<int>;
template class dLinkList<char>;