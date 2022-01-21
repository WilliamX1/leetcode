#include <iostream>
#include <cstring>
using namespace std;

struct node
{
    int l;
    int r;
    bool flag;  //代表颜色
    node():flag(0){}; //先全是白色
};
node A[100010];

int B[100010];
int B_xb;

int traverse(int t)
{
    int l, r;

    if (A[t].l != 0)
        l = traverse(A[t].l);
    else l = 0;

    B[++B_xb] = t;

    if (A[t].r != 0)
        r = traverse(A[t].r);
    else r = 0;

    return l + r + 1;
}

int color(int x)
{
    int l, r;

    if (A[x].l != 0)
        l = color(A[x].l);
    else l = 0;

    if (A[x].r != 0)
        r = color(A[x].r);
    else r = 0;

    if (A[x].flag == 1) return l + r + 1;
    else return l + r;
}

int main()
{
    int N, P, Q; scanf("%d%d%d", &N, &P, &Q);

    int x, y, z, t;

    for (int i = 1; i <= N; i++)
    {
        scanf("%d%d%d", &x, &y, &z);
        A[x].l = y;
        A[x].r = z;
    }


    for (int i = 1; i <= P; i++)
    {
        B_xb = 0;

        scanf("%d%d", &t, &x);
        y = traverse(t);
        x = x % y + 1;

        A[B[x]].flag = 1;
    }

    for (int i = 1; i <= Q; i++)
    {
        scanf("%d", &x);
        printf("%d\n", color(x));
    }


    return 0;
}
