/*#include <cstdio>
#include <cmath>
#include <memory.h>
using namespace std;

int n;
double MIN;
bool T[16];

struct node
{
    double x;
    double y;
};
node A[16];

double distance(int i, int j)
{
    double dx = (A[i].x - A[j].x) * (A[i].x - A[j].x);
    double dy = (A[i].y - A[j].y) * (A[i].y - A[j].y);
    return pow(dx + dy, 0.5);
}

void Dfs(int x, double dis)  //x代表当前点下标
{
    if (dis >= MIN) return;

    bool flag = true;

    for (int i = 1; i <= n; i++)
        if (!T[i])
        {
            T[i] = true;
            Dfs(i, dis + distance(x, i));
            T[i] = false;
            flag = false;
        }

    if (flag && dis < MIN) MIN = dis;

}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
       scanf("%lf%lf", &A[i].x, &A[i].y);
    A[0].x = A[0].y = 0;
    MIN = 2000000000.0;

    Dfs(0, 0);

    printf("%.2lf\n", MIN);

    return 0;
}*/


#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;
int X[16];
int Y[16];
double dp[16][16][16];

double dis(int& x1, int& y1, int& x2, int& y2)
{
    double dx2 = (x1 - x2) * (x1 - x2);
    double dy2 = (y1 - y2) * (y1 - y2);
    return sqrt(dx2 + dy2);
}
int main()
{
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%lf%lf", &X[i], &Y[i]);

    memset(dp, 0x7fffffff, sizeof(dp));

    int r;
    for (int step = 0; step < n; step++)
        for (int l = 1; r = l + step, r <= n; l++)
        {
            if (!step) dp[l][l][l] = dis(0, 0, X[l], Y[l]);
            else{
                for (int i = l; i < r; i++)
                    for (int j = l; j <= i; j++)
                        for (int k = i + 1; k <= r; k++)
                        {
                            dp[l][r][k] = min(dp[l][r][k], dp[l][i][j] + dp[i + 1][r][k] + dis(X[j], Y[j], X[k], Y[k]);
                            dp[l][r][j] = min()
                        }
            }
        }

}
