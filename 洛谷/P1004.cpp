#include <iostream>
#include <memory.h>
#include <cmath>
using namespace std;

int A[10][10][10][10];
int B[10][10];

int main()
{
    memset(A, 0, sizeof(A));
    memset(B, 0, sizeof(B));

    int N; cin >> N;
    int x, y, num;

    cin >> x >> y >> num;
    while(x != 0 || y != 0 || num != 0)
    {
        B[x][y] = num;
        cin >> x >> y >> num;
    }

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            for (int k = 1; k <= N; k++)
                for (int s = 1; s <= N; s++)
                {
                    A[i][j][k][s] = max(max(A[i - 1][j][k - 1][s], A[i][j - 1][k][s - 1]), max(A[i - 1][j][k][s - 1], A[i][j - 1][k - 1][s])) + B[i][j] + B[k][s];
                    if (i == k && j == s) A[i][j][k][s] -= B[i][j];
                }

    cout << A[N][N][N][N];
    return 0;
}
