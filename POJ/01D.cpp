#include <iostream>
#include <memory.h>
#include <cmath>
using namespace std;

const int N = 2000;
const int Inf = 1e9;

int A[110][N];

int main()
{
    int t; scanf("%d", &t);

    while(t--)
    {
        int n; scanf("%d", &n);

        for (int i = 0; i < 110; i++)
        {
            if (i == 0)
                for (int j = 0; j < N; j++)
                    A[i][j] = 0;
            else
                for (int j = 0; j < N; j++)
                    A[i][j] = Inf;
        }

        int m, B, P;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &m);
            for (int j = 1; j <= m; j++)
            {
                scanf("%d%d", &B, &P);
                for (int k = 1; k < N; k++)
                {
                    if (k <= B) A[i][k] = min(A[i][k], A[i - 1][k] + P);
                    else A[i][B] = min(A[i][B], A[i - 1][B] + P);
                }
            }
        }

        double MAX = 0.0;
        for (int i = 1; i < N; i++)
            MAX = max(MAX, double(i) / A[n][i]);

        printf("%.3f\n", MAX);
    }
    return 0;
}
