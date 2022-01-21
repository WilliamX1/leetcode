#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;

int H[3010][3010];
int T[3010][3010];  //上
int B[3010][3010];  //下
int L[3010][3010];  //左
int R[3010][3010];  //右

struct node
{
    int num;
    int index;
    node(int n, int i):num(n), index(i){};
};

int main()
{
    int n, m; scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &H[i][j]);

    for (int i = 1; i <= n; i++)
    {
        stack<node> s;
        for (int j = 1; j <= m; j++)
        {
            while (!s.empty() && s.top().num >= H[i][j]) s.pop();
            if (s.empty()) L[i][j] = j - 1;
            else L[i][j] = j - s.top().index - 1;
            s.push(node(H[i][j], j));
        }
        while(!s.empty()) s.pop();
        for (int j = m; j >= 1; j--)
        {
            while (!s.empty() && s.top().num >= H[i][j]) s.pop();
            if (s.empty()) R[i][j] = m - j;
            else R[i][j] = s.top().index - j - 1;
            s.push(node(H[i][j], j));
        }
    }

    for (int j = 1; j <= m; j++)
    {
        stack<node> s;
        for (int i = 1; i <= n; i++)
        {
            while (!s.empty() && s.top().num >= H[i][j]) s.pop();
            if (s.empty()) T[i][j] = i - 1;
            else T[i][j] = i - s.top().index - 1;
            s.push(node(H[i][j], i));
        }
        while(!s.empty()) s.pop();
        for (int i = n; i >= 1; i--)
        {
            while (!s.empty() && s.top().num >= H[i][j]) s.pop();
            if (s.empty()) B[i][j] = n - i;
            else B[i][j] = s.top().index - i - 1;
            s.push(node(H[i][j], i));
        }
    }

    int res = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            res = max(res, (T[i][j] + B[i][j] + L[i][j] + R[i][j] + 1) * H[i][j]);
    cout << res;


    /*int res = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            int sum = 1;  //自身
            for (int x = i - 1; x >= 1 && H[x][j] >= H[i][j]; x--)
                sum++;
            for (int x = i + 1; x <= n && H[x][j] >= H[i][j]; x++)
                sum++;
            for (int y = j - 1; y >= 1 && H[i][y] >= H[i][j]; y--)
                sum++;
            for (int y = j + 1; y <= m && H[i][y] >= H[i][j]; y++)
                sum++;
            res = max(res, sum * H[i][j]);
        }
    cout << res;*/

    return 0;
}
