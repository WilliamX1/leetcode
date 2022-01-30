#include <iostream>
#include <memory.h>
using namespace std;

int A[12][12];

int main()
{
    memset(A, 0, sizeof(A));

    for (int i = 1; i <= 10; i++)
    {
        A[i][1] = 1;
        for (int j = 1; j <= 10; j++)
        {
            A[0][j] = 1;
            if (i < j)
                A[i][j] = A[i][j - 1];
            else
                A[i][j] = A[i][j - 1] + A[i - j][j];
        }
    }

    int t, M, N; scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &M, &N);
        printf("%d\n", A[M][N]);
    }

    return 0;
}
