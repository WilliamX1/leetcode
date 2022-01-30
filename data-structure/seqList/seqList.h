#ifndef SEQLIST_H
#define SEQLIST_H
// 线性表的顺序实现
#include "list.h"
template <class elemType>
class seqList :public list<elemType>
{
private:
    elemType* data;
    int currentLength;
    int maxSize;
    void doubleSpace();                                 //扩大数组空间
public:
    seqList(int initSize = 10);
    ~seqList();
    void clear();
    int length()const;
    void insert(int i, const elemType& x);
    void remove(int i);
    int search(const elemType& x)const;
    elemType visit(int i)const;
    void traverse()const;
};
#endif // !SEQLIST_H

