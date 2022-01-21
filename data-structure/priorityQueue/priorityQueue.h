#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE
#include "queue.h"
template <class Type>
class priorityQueue:public queue<Type>
{
public:
	priorityQueue(int capacity = 100);
	priorityQueue(const Type data[], int size);
	~priorityQueue();
	bool isEmpty()const;
	void enQueue(const Type& x);
	Type deQueue();
	Type getHead()const;
private:
	int currentSize;  //队列长度
	Type* array;
	int maxSize;  //容量

	void doubleSpace();
	void buildHeap();
	void percolateDown(int hole);
};
#endif // !PRIORITYQUEUE_H

