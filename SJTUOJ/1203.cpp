#include <iostream>
#include <cstring>

using namespace std;

template <class T>
class linklist
{
public:
    struct node
    {
        T data;
        node* next;
        node(T thedata, node* n = NULL):data(thedata),next(n){};
        node():next(NULL){};
    };
    int maxSize;
    node* head;
    node* tail;
    linklist(){head = tail = new node();};
    void enQueue()
    {
        T data; cin >> data;
        tail = tail->next = new node(data);
    };
    void traverse()
    {
        node* tmp = head->next;
        while(tmp != NULL)
        {
            cout << tmp->data << " ";
            tmp = tmp->next;
        }
    }
};

int main()
{
    string cho; cin >> cho;
    if(cho == "int")
    {
        linklist<int> A, B;
        int An, Bn; cin >> An >> Bn;
        for (int i = 0; i < An; i++)
            A.enQueue();
        for (int i = 0; i < Bn; i++)
            B.enQueue();
        A.tail->next = B.head->next;
        A.traverse();
    }
    else if (cho == "char")
    {
        linklist<char> A, B;
        int An, Bn; cin >> An >> Bn;
            for (int i = 0; i < An; i++)
                A.enQueue();
            for (int i = 0; i < Bn; i++)
                B.enQueue();
            A.tail->next = B.head->next;
            A.traverse();
    }
    else if (cho == "double")
    {
        linklist<double> A, B;
        int An, Bn; cin >> An >> Bn;
            for (int i = 0; i < An; i++)
                A.enQueue();
            for (int i = 0; i < Bn; i++)
                B.enQueue();
            A.tail->next = B.head->next;
            A.traverse();
    }
    return 0;
}
