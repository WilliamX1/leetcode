#include <iostream>

using namespace std;
/*
int main()
{
    const int Y =15;
    int n, k; scanf("%d%d",&n,&k);
    int tmp, cur;
    bool flag;
    int B[10001];
    int **A = new int*[n + 1]; A[1][1] = -1;
    for (int i = 1; i <= n; i++)
        A[i] = new int[Y + 1];

    for (int i = 1; i <= n; i++)
        scanf("%d",&A[i][1]);
    for (int i = 2; i <= n; i++)
        {
            tmp = A[i][1];
            cur = 1;
            while(tmp != 1)
                tmp = A[i][++cur] = A[tmp][0];
            A[i][0] = cur;
        }
    for (int i = 1; i <= k; i++)
    {
        scanf("%d",&tmp);
        for (int i = 1; i <= tmp; i++)
             scanf("%d",&B[i]);

    }
    return 0;
}*/

struct node
{
    int data;
    node* left;
    node* right;
    node(int d, node* l, node* r)
    :data(d),left(l),right(r){};
};

int main()
{
    node* head = new node(1, NULL, NULL);
    //head有左右孩子指针暂时分别置为空
    node* cur = *&head->left;
    cur = new node(2, NULL, NULL);
    //cur = *&cur->left;  //指向head左孩子

    //我认为：head->left里已经存储了数据2
    //实际上：head->left依旧为空指针
    cout << head->left;
    return 0;
}
