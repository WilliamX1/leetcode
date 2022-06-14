#include "seqList.h"
#include <iostream>
using namespace std;

template <class elemType> seqList<elemType>::seqList(int initSize)
{
    data = new elemType[initSize];
    maxSize = initSize;
    currentLength = 0;
}
template <class elemType> seqList<elemType>::~seqList()
{
    delete[] data;
}
template <class elemType> void seqList<elemType>::clear()
{
    currentLength = 0;
}
template <class elemType> int seqList<elemType>::length() const
{
    return currentLength;
}
template <class elemType> void seqList<elemType>::insert(int i, const elemType &x)
{
    if (currentLength >= maxSize)
        doubleSpace();
    for (int j = currentLength - 1; j >= i; --j)
        data[j + 1] = data[j];
    data[i] = x;
    ++currentLength;
}
template <class elemType> void seqList<elemType>::remove(int i)
{
    if (i >= currentLength)
        cout << "Cannot find the element!";
    for (int j = i; j < currentLength - 1; ++j)
        data[j] = data[j + 1];
    --currentLength;
}
template <class elemType> int seqList<elemType>::search(const elemType &x) const
{
    for (int i = 0; i < currentLength; ++i)
        if (data[i] == x)
            return i;
    return -1;
}
template <class elemType> elemType seqList<elemType>::visit(int i) const
{
    return i < currentLength ? data[i] : -1;
}
template <class elemType> void seqList<elemType>::traverse() const
{
    cout << endl;
    for (int i = 0; i < currentLength; ++i)
        cout << data[i] << ' ';
}
template <class elemType> void seqList<elemType>::doubleSpace()
{
    elemType *tmp = data;
    maxSize *= 2;
    data = new elemType[maxSize];
    for (int i = 0; i < currentLength; ++i)
        data[i] = tmp[i];
    delete[] tmp;
}
template class seqList<int>;
template class seqList<char>;