#ifndef TREE_H
#define TREE_H
//���ĳ����ඨ��
template <class T> class tree
{
  public:
    virtual void clear() = 0;                //ɾ���������еĽ��
    virtual bool isEmpty() = 0;              //�ж��Ƿ�Ϊ����
    virtual T root(T flag) const = 0;        //�ҳ����ĸ���㣬����ǿ������򷵻�һ������ֵ
    virtual T parent(T x, T flag) const = 0; //�ҳ����x�ĸ����ֵ�����x�����ڻ�x�Ǹ���㣬�򷵻�һ������ֵ
    virtual T child(T x, int i,
                    T flag) const = 0;   //�ҽ��x�ĵ�i���ӽڵ�ֵ�����x�����ڻ�x�ĵ�i�����Ӳ����ڣ��򷵻�һ������ֵ
    virtual void remove(T x, int i) = 0; //ɾ�����x�ĵ�i������
    virtual void traverse() const = 0;   //�������ϵ�ÿһ�����
};
#endif // !TREE_H
