#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;
int A[105];
int dpL[105];
int dpR[105];

int main()
{
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &A[i]);

    for (int i = 1; i <= n; i++) dpL[i] = 1;
    for (int i = 2; i <= n; i++)
        for (int j = i - 1; j >= 1; j--)
            if (A[i] > A[j])
                dpL[i] = max(dpL[i], dpL[j] + 1);

    for (int i = 1; i <= n; i++) dpR[i] = 1;
    for (int i = n - 1; i >= 1; i--)
        for (int j = i + 1; j <= n; j++)
            if (A[i] > A[j])
                dpR[i] = max(dpR[i], dpR[j] + 1);

    int res = 0;
    for (int i = 1; i <= n; i++)
        res = max(res, dpL[i] + dpR[i] - 1);
    printf("%d", n - res);
    return 0;
}
