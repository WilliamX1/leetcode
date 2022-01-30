#include <iostream>
#include <memory.h>
using namespace std;

int A[10][10];
int B[10][10];

int T[10];

int main()
{
    int R, C; R = 5, C = 6;

    memset(A, 0, sizeof(A));
    memset(B, 0, sizeof(B));
    memset(T, 0, sizeof(T));

    for (int i = 1; i <= R; i++)
        for (int j = 1; j <= C; j++)
            scanf("%d", &A[i][j]);

    B[1][1] = -1;
    for (int i = 1; i <= 64; i++)
    {
        B[1][1]++;
        for (int k = 1; k <= C; k++)
            if (B[1][k] == 2) {B[1][k] = 0; B[1][k + 1]++;}
            else break;

        for (int j = 1; j <= R; j++)
        {
            for (int k = 1; k <= C; k++)
                B[j + 1][k] = (A[j][k] + B[j - 1][k] + B[j][k - 1] + B[j][k + 1] + B[j][k]) % 2;
        }

        int s;
        for (s = 1; s <= C && B[R + 1][s] == 0; s++);
        if (s > C)
        {
            for (int j = 1; j <= R; j++)
            {
                for (int k = 1; k <= C; k++)
                    printf("%d ", B[j][k]);
                printf("\n");
            }
            break;
        }
    }

    return 0;
}
