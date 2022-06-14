#ifndef SEQQUEUE_H
#define SEQQUEUE_H
//À≥–Ú—≠ª∑∂”¡–
#include "queue.h"
template <class elemType> class seqQueue : public queue<elemType>
{
  private:
    elemType *elem;
    int maxSize;
    int front, rear;
    void doubleSpace();

  public:
    seqQueue(int intiSize = 10);
    ~seqQueue();
    bool isEmpty() const;
    void enQueue(const elemType &x);
    elemType deQueue();
    elemType getHead() const;
};
#endif // !SEQQUEUE_H