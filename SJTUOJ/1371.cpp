#include <iostream>
#include <cstdio>
using namespace std;
/*const int N = 2000;
int sum[N + 1][N + 1];
int main()
{
    int n, m; scanf("%d%d",&n,&m);
    int tmp, x, y;
    
    for (int i = 0; i <= N; i++)
        for (int j = 0; j <= N; j++)
            sum[i][j] = 0;

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tmp);
        for (int j = 0; j <= tmp; j++)
            for (int k = tmp; k <= N; k++)
                sum[j][k] += 1;
    }

    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &x, &y);
        printf("%d\n", sum[x][y]);
    }
    return 0;
}*/

int main()
{
    int N, M, tmp, x, y; cin >> N >> M;
    const int K = 1000000;
    int* arr = new int[K + 1];
    for (int i = 0; i <= K; i++)
        arr[i] = 0;
    for (int i = 1; i <= N; i++)
    {
        scanf("%d", tmp);
        arr[tmp] += 1;
    }
    for (int i = 0; i < N; i++)
        arr[i + 1] += arr[i];
    for (int i = 1; i <= M; i++)
    {
        scanf("%d%d", &x, &y);
        printf("%d\n",arr[y] - arr[x - 1]);
    }
    return 0;
}