#ifndef LINKLIST_H
#define LINKLIST_H
//ջ������ʵ��
#include "stack.h"
template <class elemType> class linkStack : public stack<elemType>
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
        node() : next(NULL)
        {
        }
        ~node()
        {
        }
    };

    node *top_p;

  public:
    linkStack();
    ~linkStack();
    bool isEmpty() const;
    void push(const elemType &x);
    elemType pop();
    elemType top() const;
};
#endif // !LINKLIST_H