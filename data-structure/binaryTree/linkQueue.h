#ifndef LINKQUEUE_H
#define LINKQUEUE_H
#include "queue.h"
//链接循环队列
template <class elemType> class linkQueue : public queue<elemType>
{
  private:
    struct node
    {
        elemType data;
        node *next;
        node(const elemType &x, node *N = NULL)
        {
            data = x;
            next = N;
        }
        node() : next(NULL){};
        ~node(){};
    };

    node *front, *rear;

  public:
    linkQueue();
    ~linkQueue();
    bool isEmpty() const;
    void enQueue(const elemType &x);
    elemType deQueue();
    elemType getHead() const;
    elemType getTail() const;
};
#endif