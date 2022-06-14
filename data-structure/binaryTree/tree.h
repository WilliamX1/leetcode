#ifndef TREE_H
#define TREE_H
//树的抽象类定义
template <class T> class tree
{
  public:
    virtual void clear() = 0;                //删除树中所有的结点
    virtual bool isEmpty() = 0;              //判断是否为空树
    virtual T root(T flag) const = 0;        //找出树的根结点，如果是空树，则返回一个特殊值
    virtual T parent(T x, T flag) const = 0; //找出结点x的父结点值，如果x不存在或x是根结点，则返回一个特殊值
    virtual T child(T x, int i,
                    T flag) const = 0;   //找结点x的第i个子节点值，如果x不存在或x的第i个儿子不存在，则返回一个特殊值
    virtual void remove(T x, int i) = 0; //删除结点x的第i课子树
    virtual void traverse() const = 0;   //访问树上的每一个结点
};
#endif // !TREE_H
