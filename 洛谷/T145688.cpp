#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;

int A[1000010];
struct node
{
    int x;
    int y;
};
node B[1000010];
int B_index = 0;

int main()
{
    int n, m; scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) A[i] = i;

    int cur = 0, ch, x, y;
    while(m--)
    {
        scanf("%d", &ch);
        if (ch == 1 || ch == 2)
            cur = ch, B_index = 0;
        else if (ch == 3)
            B_index++, scanf("%d%d", &B[B_index].x, &B[B_index].y);
        else
            B_index++, B[B_index].x = -1;  //代表序列翻转
    }

    bool head = true; //头从哪一方向
    if (cur == 2)
        head = false;  //头从远端
    for (int i = 1; i <= B_index; i++)
        if (B[i].x == -1)
            head = !head;
        else
            if (head)
            {
                int tmp = A[B[i].x];
                A[B[i].x] = A[B[i].y];
                A[B[i].y] = tmp;
            }
            else
            {
                int tmp = A[n + 1 - B[i].x];
                A[n + 1 - B[i].x] = A[n + 1 - B[i].y];
                A[n + 1 - B[i].y] = tmp;
            }

    if (head)
        for (int i = 1; i <= n; i++) printf("%d ", A[i]);
    else for (int i = n; i >= 1; i--) printf("%d ", A[i]);

    return 0;
}
