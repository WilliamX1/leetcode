#ifndef LIST_H
#define LIST_H
// ���Ա�ĳ�����
template <class elemType>
class list
{
public:
    virtual void clear() = 0;                           //ɾ�����Ա��е���������Ԫ��
    virtual int length()const = 0;                     //�����Ա�ĳ���
    virtual void insert(int i, const elemType& x) = 0;  //�ڵ�i��λ�ò����һ��Ԫ��
    virtual void remove(int i) = 0;                     //ɾ����i��λ�õ�Ԫ��
    virtual int search(const elemType& x)const = 0;     //����ĳ��Ԫ��x�����Ա����Ƿ����
    virtual elemType visit(int i)const = 0;             //�������Ա��е�i��λ��Ԫ�ص�ֵ
    virtual void traverse()const = 0;                   //����������Ա��ÿһ����Ԫ��
    virtual ~list() {};
};
#endif

