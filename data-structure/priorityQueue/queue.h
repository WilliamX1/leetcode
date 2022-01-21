#pragma once
#ifndef QUEUE_H
#define QUEUE_H
template <class elemType>
class queue
{
public:
	virtual bool isEmpty()const = 0;  //�жӿ�
	virtual void enQueue(const elemType& x) = 0;  //����
	virtual elemType deQueue() = 0;  //����
	virtual elemType getHead()const = 0;  //����ͷԪ��
	virtual ~queue() {};  //����������
};
#endif // !QUEUE_H

