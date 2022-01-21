#include <iostream>

using namespace std;

class Stack
{
    struct node
    {
        char ch;
        int data;
    };
    node* A;
    int cur;
public:
    Stack(const int N){A = new node[N];cur = -1;};
    void push()
    {
        getchar();
        scanf("%c",&A[++cur].ch);
        if (cur == 0)
            A[cur].data = 0;
        else
        {
            int tmp = A[cur - 1].data;
            if (tmp == -1) A[cur].data = cur;  //
            else if (A[cur].ch == ')' && A[tmp].ch == '('
                    || A[cur].ch == ']' && A[tmp].ch == '['
                    || A[cur].ch == '}' && A[tmp].ch == '{')
                    A[cur].data = tmp == 0 ? -1 : A[tmp - 1].data; //
            else
                A[cur].data = cur;
        }
    }
    void pop()
    {
        if (cur != -1)
            cur--;
        return;
    }
    void top()
    {
        if (cur == -1) return;
        printf("%c\n",A[cur].ch);
    }
    bool pipei()
    {
        if (cur == -1) return true;
        return A[cur].data == -1;
    }


};
int main()
{
    int n; scanf("%d",&n);
    Stack S(n);
    int choice; char ch;
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            S.push();break;
        case 2:
            S.pop();break;
        case 3:
            S.top();break;
        case 4:
            if (S.pipei())
                printf("%s\n","YES");
            else
                printf("%s\n","NO");
            break;
        }
    }
    return 0;
}
