#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;

int A[100010];
int From[100010];
int To[100010];
int dp[100010];
struct node
{
    int num;
    int index;
    node(int n, int i):num(n), index(i){};
    node(){};
};
bool myCompare(node a, node b)
{
    return a.num < b.num;
}
node T[100010];
int T_xb = 0;
int main()
{
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &From[i]);
    for (int i = 1; i <= n; i++)
        scanf("%d", &To[i]);
    for (int i = 1; i <= n; i++)
        A[From[i]] = i;
    for (int i = 1; i <= n; i++)
        To[i] = A[To[i]];
    //for (int i = 1; i <= n; i++)
       // cin >> To[i];

    memset(dp, 0, sizeof(dp));
    dp[1] = 1;
    ++T_xb; T[T_xb].num = To[1]; T[T_xb].index = 1;

    for (int i = 2; i <= n; i++)
    {
        if (To[i] >= T[T_xb].num)
        {
            dp[i] = dp[T[T_xb].index] + 1;
            T_xb++;
            T[T_xb].index = i;
            T[T_xb].num = To[i];
        }
        else
        {
            node* Q = upper_bound(T + 1, T + T_xb + 1, node(To[i], i), myCompare);
            dp[i] = dp[Q->index];
            Q->index = i;
            Q->num = To[i];
        }
    }
    cout << *max_element(dp + 1, dp + n + 1);
    return 0;
}

/*
const int N = 100000 + 10;
int A[N];
int B[N];
int dp[2][N];
int main()
{
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &A[i]);
    for (int i = 1; i <= n; i++)
        scanf("%d", &B[i]);

    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            if (A[i] == B[j])
                dp[i % 2][j] = dp[(i - 1) % 2][j - 1] + 1;
            else
                dp[i % 2][j] = max(dp[(i - 1) % 2][j], dp[i % 2][j - 1]);
        }

    printf("%d", dp[n % 2][n]);
    return 0;
}
*/

