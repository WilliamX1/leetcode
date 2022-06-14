#ifndef linkStack
#define linkStack

//ջ������ʵ��
template <class elemType> class linkStack : public Stack<elemType>
{
  private:
    struct node
    {
        elemType data;
        node *next;
        node(const elemType &x, node *N = NULL)
        {
            data = x;
            next = N;
        }
        node() : next(NULL)
        {
        }
        ~node()
        {
        }
    };

    node *top_p;

  public:
    linkStack();
    ~linkStack();
    bool isEmpty() const;
    void push(const elemType &x);
    elemType pop();
    elemType top() const;
};
#endif