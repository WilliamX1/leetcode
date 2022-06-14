#ifndef stack
#define stack

//ջ�ĳ�����
template <class elemType> class stack
{
  public:
    virtual bool isEmpty() const = 0;         //��ջ��
    virtual void push(const elemType &x) = 0; //��ջ
    virtual elemType pop() = 0;               //��ջ
    virtual elemType top() const = 0;         //ȡջ��Ԫ��
    virtual ~stack()
    {
    } //����������
};
#endif // !stack