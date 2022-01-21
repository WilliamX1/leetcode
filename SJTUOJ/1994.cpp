#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;
int A[512][512];
int ans[512][512];
int N, M;

void Dfs(int x, int y, int state)
{
    ans[x][y] = state;
    if (x > 0 && !ans[x - 1][y]) Dfs(x - 1, y, state);
    if (x < N - 1 && !ans[x + 1][y]) Dfs(x + 1, y, state);
    if (y > 0 && !ans[x][y - 1]) Dfs(x, y - 1, state);
    if (y < N - 1 && !ans[x][y + 1]) Dfs(x, y + 1, state);
    return;
}
int main()
{
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            scanf("%d", &A[i][j]);
            ans[i][j] = A[i][j];
        }

    int res = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (!ans[i][j])
                Dfs(i, j, ++res);
    printf("%d", res);

    return 0;
}
