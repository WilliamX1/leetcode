#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;
const int N = 6;
int A[N][N];
bool T[N][N];
int res;
int start_x, start_y, end_x, end_y;

void Dfs(int x, int y, int state, int ans)
{
    int pay = A[x][y] * state;
    state = (pay % 4) + 1;

    ans += pay;
    if (ans >= res) return;
    if (x == end_x && y == end_y){
        res = min(res, ans);
        return;
    }
    T[x][y] = true;

    if (x > 0 && !T[x - 1][y]) Dfs(x - 1, y, state, ans);
    if (x < N - 1 && !T[x + 1][y]) Dfs(x + 1, y, state, ans);
    if (y > 0 && !T[x][y - 1]) Dfs(x, y - 1, state, ans);
    if (y < N - 1 && !T[x][y + 1]) Dfs(x, y + 1, state, ans);

    T[x][y] = false;
    return;
};

int main()
{
    int t; scanf("%d", &t);
    while(t--){
        memset(T, 0, sizeof(T));
        res = 0x7fffffff;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                scanf("%d", &A[i][j]);
        scanf("%d%d%d%d", &start_x, &start_y, &end_x, &end_y);
        Dfs(start_x, start_y, 0, 0);

        printf("%d\n", res);
    }

    return 0;
}
