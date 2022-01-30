#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;
struct nodeA
{
    int no_more;
    long long int leave;
};
nodeA N_A[1000010];
int A[1000010];
int B[1000010];
struct nodeB
{
    int no_more;
    long long int come;
};
nodeB N_B[1000010];
int main()
{
    int n, m, k; scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d", &A[n - i + 1]);
    long long int A_sum = 0;
    for (int i = 1; i <= n; i++)
    {
        N_A[i].leave = A_sum;
        N_A[i].no_more = A[i];
        A_sum += (long long)A[i];
    }


    for (int i = 1; i <= m; i++)
        scanf("%d", &B[i]);
    sort(B + 1, B + m + 1);  //从小到大排序
    long long int B_sum = 0;
    for (int i = 1; i <= k; i++)
        B_sum += (long long)B[i];
    N_B[1].come = B_sum;
    N_B[1].no_more = B[k];
    for (int i = k + 1; i <= m; i++)
    {
        B_sum = B_sum - (long long)B[i - k] + (long long)B[i];
        N_B[i - k + 1].come = B_sum;
        N_B[i - k + 1].no_more = B[i];
    }

    int A_index = n, B_index = m - k + 1;

    long long int res = 0;
    int i = 1;
    for (int j = 1; j <= B_index; j++)
    {
        while(N_A[i].no_more <= N_B[j].no_more) i++;
        if (i > n) break;
        res = max(res, N_B[j].come - N_A[i].leave);
    }
    for (int i = 1; i <= n; i++)
        res += (long long)A[i];
    cout << res;
    return 0;
}
