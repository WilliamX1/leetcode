#include <iostream>
#include <algorithm>
using namespace std;
struct node
{
    int ci;  //多少钱
    int Ti;  //多少天
};
int A[500020];  //旅行天数
long long int B[500020]; //当前花费最少
node C[30];  //优惠票价
bool myCompare(node A, node B){return A.ci < B.ci;};

int main()
{
    int n, m, k; cin >> n >> m >> k;
    int i, j, s;
    A[0] = B[0] = C[0].ci = C[0].Ti = 0;

    for (i = 1; i <= n; i++)
        {scanf("%d",&A[i]); B[i] = i * k;};
    for (i = 1; i <= m; i++)
        scanf("%d%d", &C[i].Ti, &C[i].ci);

    sort(C + 1, C + m + 1, myCompare);

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
        {
            for (s = i - 1; s > 0 && A[i] - A[s] < C[j].Ti; s--);
            B[i] = min(B[i], C[j].ci + B[s]);
        }
        B[i] = min(B[i], B[i - 1] + k);
    }
    cout << B[n];

    return 0;
}
