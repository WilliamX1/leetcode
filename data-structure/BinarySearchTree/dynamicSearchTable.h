#ifndef DYNAMICSEARCHTABLE_H
#define DYNAMICSEARCHTABLE_H
#include "SET.h"
template <class KEY, class OTHER> class dynamicSearchTable
{
  public:
    virtual SET<KEY, OTHER> *find(const KEY &x) const = 0;
    virtual void insert(const SET<KEY, OTHER> &x) = 0;
    virtual void remove(const KEY &x) = 0;
    virtual ~dynamicSearchTable(){};
};
#endif