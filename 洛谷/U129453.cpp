#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;
long long n, k;

long long Dfs(long long left, long long right)
{
    long long mid = (left + right) >> 1;

    long long L = mid - left - 1, R = right - mid - 1;

    if (L < k && R < k)
        return 0;
    else if (L < k)
        return Dfs(mid, right);
    else if (R < k)
        return Dfs(left, mid);

    long long iter = (k << 1) + 1;
    if (L < iter && R < iter)
        return 1;
    else if (L < iter)
        return Dfs(mid, right) + 1;
    else if (R < iter)
        return Dfs(left, mid) + 1;

    if ((left + right) & 1) return Dfs(left, mid) + Dfs(mid, right) + 1;
    else return (Dfs(left, mid) << 1) + 1;
}
int main()
{
    scanf("%lld%lld", &n, &k);
    cout << 1 + Dfs(1, n + 1);
    return 0;
}
