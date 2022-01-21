#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

long long int A[1000010];

int main()
{
    int n, k; scanf("%d%d", &n, &k);
    int a, b;

    memset(A, 0, sizeof(A));
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", &a, &b);
        A[a] += (long long)b;
    }

    long long int res = -1;
    long long int tmp;

    for (int i = 0; i <= 1000000 - k; i++)
    {
        tmp = min(A[i], A[i + k]);
        if (tmp == 0) continue;  //代表某种没有

        if (k == 0)  //特殊处理0
            if (tmp == 1) continue;
            else res = max(res, tmp * i);
        else
            res = max(res, tmp * (i + i + k));
    }

    if (res == -1) cout << "NO";
    else cout << res;

    return 0;
}
