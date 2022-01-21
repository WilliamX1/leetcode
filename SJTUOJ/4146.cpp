#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;

int main()
{
    int n, B; scanf("%d%d", &n, &B);
    int A[128];
    for (int i = 1; i <= n; i++)
        scanf("%d", &A[i]);

    int ans[128];
    int cur = 0, ans_index = 0;
    for (int i = 1; i < n; i++)
    {
        if (A[i] & 1) cur++;
        if (cur == i - cur)
            ans[++ans_index] = abs(A[i] - A[i + 1]);
    }
    sort(ans + 1, ans + ans_index + 1, less<int>());

    //for (int i = 1; i <= ans_index; i++) cout << ans[i] << " ";

    int res = 0;
    for (int i = 1; i <= ans_index; i++)
        if (B >= ans[i])
            res++, B -= ans[i];
    cout << res;

    return 0;
}
