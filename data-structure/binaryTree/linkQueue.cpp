#include "linkQueue.h"
#include "binaryTree.h"
#include <iostream>
using namespace std;
template <class elemType> linkQueue<elemType>::linkQueue()
{
    front = rear = NULL;
}
template <class elemType> linkQueue<elemType>::~linkQueue()
{
    node *tmp;
    while (front != NULL)
    {
        tmp = front->next;
        delete front;
        front = tmp;
    }
}
template <class elemType> bool linkQueue<elemType>::isEmpty() const
{
    return front == NULL;
}
template <class elemType> void linkQueue<elemType>::enQueue(const elemType &x)
{
    if (rear == NULL)
        front = rear = new node(x);
    else
        rear = rear->next = new node(x);
}
template <class elemType> elemType linkQueue<elemType>::deQueue()
{
    node *tmp = front;
    elemType value = front->data;
    front = front->next;
    if (front == NULL)
        rear = NULL;
    delete tmp;
    return value;
}
template <class elemType> elemType linkQueue<elemType>::getHead() const
{
    return front->data;
}
template <class elemType> elemType linkQueue<elemType>::getTail() const
{
    return rear->data;
}
bool putBuffer(linkQueue<int> *buffer, int size, int in)
{
    int avail = -1, max = 0; // availΪ����ʵĻ�����кţ�maxΪ�ö���βԪ�صı��

    for (int j = 0; j < size; ++j)
    { //Ѱ�Һ��ʵĶ���
        if (buffer[j].isEmpty())
        { //�ҵ��ն��У�����
            if (avail == -1)
                avail = j;
        }
        else if (buffer[j].getTail() < in && buffer[j].getTail() > max)
        {
            avail = j;
            max = buffer[j].getTail();
        }
    }

    if (avail != -1)
    {
        buffer[avail].enQueue(in);
        cout << in << "���뻺����" << avail << endl;
        return true;
    }
    else
    {
        cout << "�޿��еķ���" << endl;
        return false;
    }
}
template class linkQueue<binaryTree<int>::Node *>;
template class linkQueue<binaryTree<char>::Node *>;