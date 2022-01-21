#include <iostream>
#include <memory.h>
using namespace std;

int A[1010][1010];

int main()
{
    int n, m, p; scanf("%d%d%d", &n, &m, &p);
    memset(A, 0, sizeof(A));
    for (int i = 0; i <= n + 1; i++)
        A[i][0] = A[i][m + 1] = 1;
    for (int j = 0; j <= m + 1; j++)
        A[0][j] = A[n + 1][j] = 1;

    if (p)
    {
        int dir = 0; //��0����1����2����3

        A[1][1] = 1;
        int x = 1, y = 1;
        for (int i = 2; i <= m * n; i++)
        {
            if (dir == 0) //��
                if (A[x][y + 1] == 0)
                    A[x][++y] = i;
                else
                {
                    dir++;
                    A[++x][y] = i;
                }
            else if (dir == 1) //��
                if (A[x + 1][y] == 0)
                    A[++x][y] = i;
                else
                {
                    dir++;
                    A[x][--y] = i;
                }
            else if (dir == 2) //��
                if (A[x][y - 1] == 0)
                    A[x][--y] = i;
                else
                {
                    dir++;
                    A[--x][y] = i;
                }
            else if (dir == 3) //��
                if (A[x - 1][y] == 0)
                    A[--x][y] = i;
                else
                {
                    dir = 0;
                    A[x][++y] = i;
                }
        }
    }
    else if (!p)
    {
        int dir = 0; //��0����1����2����3

        A[1][1] = 1;
        int x = 1, y = 1;
        for (int i = 2; i <= m * n; i++)
        {
            if (dir == 0) //��
                if (A[x + 1][y] == 0)
                    A[++x][y] = i;
                else
                {
                    dir++;
                    A[x][++y] = i;
                }
            else if (dir == 1) //��
                if (A[x][y + 1] == 0)
                    A[x][++y] = i;
                else
                {
                    dir++;
                    A[--x][y] = i;
                }
            else if (dir == 2) //��
                if (A[x - 1][y] == 0)
                    A[--x][y] = i;
                else
                {
                    dir++;
                    A[x][--y] = i;
                }
            else if (dir == 3) //��
                if (A[x][y - 1] == 0)
                    A[x][--y] = i;
                else
                {
                    dir = 0;
                    A[++x][y] = i;
                }
        }

    }


    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            printf("%d ", A[i][j]);
        printf("\n");
    }
    return 0;
}
