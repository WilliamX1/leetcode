#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;

inline long long read()
{
    long long x;
    scanf("%lld", &x);
    return x;
}
inline void print(__int128 x)
{
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}
struct node
{
    __int128 l;
    __int128 r;
};
node A[1010];


bool myCompare(node a, node b)
{
    return a.l * a.r < b.l * b.r;
}
int main()
{
    int n; cin >> n;
    for (int i = 0; i <= n; i++)
    {
        A[i].l = read();
        A[i].r = read();
    }
    sort(A + 1, A + n + 1, myCompare);

    __int128 cur = 1;
    __int128 M = 0;
    __int128 tmp;
    for (int i = 0; i < n; i++)
    {
        cur *= A[i].l;
        if (cur > A[i + 1].r * M)
            M = cur / __int128(A[i + 1].r);
    }
    print(M);
    return 0;
}
