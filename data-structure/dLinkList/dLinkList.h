#ifndef DLINKLIST_H
#define DLINKLIST_H
//双链表的实现
#include "list.h"
template <class elemType> class dLinkList : public list<elemType>
{
  private:
    struct node
    {
        elemType data;
        node *prev, *next;

        node(const elemType &x, node *p = NULL, node *n = NULL)
        {
            data = x;
            prev = p;
            next = n;
        }
        node() : next(NULL), prev(NULL)
        {
        }
        ~node()
        {
        }
    };

    node *head, *tail;
    int currentLength;

    node *move(int i) const;

  public:
    dLinkList();
    ~dLinkList()
    {
        clear();
        delete head;
        delete tail;
    }

    void clear();
    int length() const
    {
        return currentLength;
    }
    void insert(int i, const elemType &x);
    void remove(int i);
    int search(const elemType &x) const;
    elemType visit(int i) const;
    void traverse() const;
};
#endif // !DLINKLIST_H
