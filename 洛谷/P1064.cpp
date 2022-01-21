#include <bits/stdc++.h>

using namespace std;

struct node
{
    int v; //价格
    int p; //重要度
    int q; //对应主件
};
node A[80];

int B[4000];  //价格为i时重要度最大为j

int main()
{
    int n, k; cin >> n >> k;
    n /= 10;
    for (int i = 1; i <= k; i++)
    {
        cin >> A[i].v >> A[i].p >> A[i].q;
        A[i].p *= A[i].v;
        A[i].v /= 10;
    }

    memset(B, 0, sizeof(B));
    for (int i = 1; i <= k; i++)
        if (A[i].q == 0)
            B[A[i].v] = A[i].p;
        else
        {
            int x = A[i].q;  //对应主件
            if (A[i].v + A[x].v <= n)
                B[A[i].v + A[x].v] = max(B[A[i].v + A[x].v], A[i].p + A[x].p);

            for (int j = i - 1; j >= 1; j--)
                if (A[j].q == A[i].q && A[j].v + A[i].v + A[x].v <= n)
                    B[A[j].v + A[i].v + A[x].v] = max(B[A[j].v + A[i].v + A[x].v], A[j].p + A[i].p + A[x].p);
        }

    for (int i = 0; i <= n; i++)
    {
        for (int j = i - 1; j >= i / 2; j--)
            B[i] = max(B[i], B[j] + B[i - j]);
        //cout << B[i] << " ";
    }
    cout << B[n];

    return 0;
}
