#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;


struct node
{
    int lchild;
    int brother;
    bool cur;  //代表状态，是死是活
    bool isRoot;  //是否是根结点
    node():lchild(-1), brother(-1), cur(0),isRoot(0){};
};

int main()
{
    int N; scanf("%d", &N);
    char ch;
    int x, y, tmp, sum = 1;

    node* A = new node[N + 1];

    A[1].cur = A[1].isRoot = 1;

    for (int i = 1; i <= N; i++)
    {
        scanf("%c%c", &ch, &ch);
        if (ch == 'B')
        {
            scanf("%d%d", &x, &y);
            A[y].cur = 1;  //全部活过来

            if (A[x].lchild == -1) A[x].lchild = y;
            else
            {
                tmp = A[x].lchild;
                while(A[tmp].brother != -1)
                    tmp = A[tmp].brother;
                A[tmp].brother = y;
            }
        }
        else
        {
            scanf("%d", &x);
            A[x].cur = 0;

            tmp = A[x].lchild;
            //如果存在左儿子
            while(tmp != -1)
            {
                A[tmp].isRoot = 1;
                if (A[tmp].cur == 1) sum++;

                tmp = A[tmp].brother;
            }
            if (A[x].isRoot == 1) sum--;
            printf("%d\n", sum);
        }
    }
    return 0;
}
