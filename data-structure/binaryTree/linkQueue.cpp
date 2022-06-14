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
    int avail = -1, max = 0; // avail为最合适的缓冲队列号，max为该队列尾元素的编号

    for (int j = 0; j < size; ++j)
    { //寻找合适的队列
        if (buffer[j].isEmpty())
        { //找到空队列，备用
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
        cout << in << "移入缓冲区" << avail << endl;
        return true;
    }
    else
    {
        cout << "无可行的方案" << endl;
        return false;
    }
}
template class linkQueue<binaryTree<int>::Node *>;
template class linkQueue<binaryTree<char>::Node *>;