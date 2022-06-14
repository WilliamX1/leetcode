#ifndef SLINKLIST_H
#define SLINKLIST_H
#include "list.h"
// 线性表的链接实现
template <class elemType> class sLinkList : public list<elemType>
{
  private:
    struct node
    {
        elemType data;
        node *next;

        node(const elemType &x, node *n = NULL)
        {
            data = x;
            next = n;
        }
        node() : next(NULL)
        {
        }
        ~node()
        {
        }
    };

    node *head;        //头指针
    int currentLength; //表长

    node *move(int i) const; //返回第i个结点的地址

  public:
    sLinkList();
    ~sLinkList()
    {
        clear();
        delete head;
    };
    void clear();
    int length() const
    {
        return currentLength;
    }
    void insert(int i, const elemType &x);
    void remove(int i, const elemType &x);
    int search(const elemType &x) const;
    elemType visit(int i) const;
    void traverse() const;
};
#endif // !SLINKLIST_H
