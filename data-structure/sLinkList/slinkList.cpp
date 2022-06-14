#include "slinkList.h"
#include <iostream>
using namespace std;

template <class elemType> typename sLinkList<elemType>::node *sLinkList<elemType>::move(int i) const
{
    node *p = head;
    for (int j = i; j > 0; --j)
        p = p->next;
    return p;
}
template <class elemType> sLinkList<elemType>::sLinkList()
{
    head = new node;
    currentLength = 0;
}
template <class elemType> void sLinkList<elemType>::clear()
{
    node *p = head->next, *q;
    head->next = NULL;
    while (p != NULL)
    {
        q = p;
        p = p->next;
        delete q;
    }
    currentLength = 0;
}
template <class elemType> void sLinkList<elemType>::insert(int i, const elemType &x)
{
    node *pos;

    pos = move(i - 1);
    pos->next = new node(x, pos->next);
    ++currentLength;
}
template <class elemType> void sLinkList<elemType>::remove(int i, const elemType &x)
{
    node *p, *q;

    p = move(i - 1);
    q = p->next;
    p->next = q->next;
    delete q;
    --currentLength;
}
template <class elemType> int sLinkList<elemType>::search(const elemType &x) const
{
    node *p = head->next;
    int i = 0;

    while (p != NULL && p->data != x)
    {
        p = p->next;
        ++i;
    }
    if (p = NULL)
        return -1;
    else
        return i;
}
template <class elemType> elemType sLinkList<elemType>::visit(int i) const
{
    return move(i)->data;
}
template <class elemType> void sLinkList<elemType>::traverse() const
{
    node *p = head->next;
    cout << endl;
    while (p != NULL)
    {
        cout << p->data << ' ';
        p = p->next;
    }
    cout << endl;
}
template class sLinkList<int>;
template class sLinkList<char>;