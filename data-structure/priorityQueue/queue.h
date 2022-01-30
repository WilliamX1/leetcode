#pragma once
#ifndef QUEUE_H
#define QUEUE_H
template <class elemType>
class queue
{
public:
	virtual bool isEmpty()const = 0;  //判队空
	virtual void enQueue(const elemType& x) = 0;  //进队
	virtual elemType deQueue() = 0;  //出队
	virtual elemType getHead()const = 0;  //读队头元素
	virtual ~queue() {};  //虚析构函数
};
#endif // !QUEUE_H

