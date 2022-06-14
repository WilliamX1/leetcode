#include <bits/stdc++.h>

using namespace std;

class Solution
{
  public:
    struct node
    {
        int x;
        int y;
        int cnt;
        node(){};
        node(int xx, int yy, int cc) : x(xx), y(yy), cnt(cc){};
    };
    int nearestExit(vector<vector<char>> &maze, vector<int> &entrance)
    {
        int m = maze.size(), n = maze[0].size();
        vector<vector<int>> v(m, vector<int>(n, 0x7fffffff));
        v[entrance[0]][entrance[1]] = 0;
        queue<node> q;
        q.push(node(entrance[0], entrance[1], 0));

        while (!q.empty())
        {
            node cur = q.front();
            q.pop();
            if ((cur.x != entrance[0] || cur.y != entrance[1]) &&
                (cur.x == 0 || cur.x == m - 1 || cur.y == 0 || cur.y == n - 1))
                return cur.cnt;

            if (cur.x > 0 && maze[cur.x - 1][cur.y] == '.' && cur.cnt + 1 < v[cur.x - 1][cur.y])
            {
                q.push(node(cur.x - 1, cur.y, cur.cnt + 1));
                v[cur.x - 1][cur.y] = cur.cnt + 1;
            };
            if (cur.x < m - 1 && maze[cur.x + 1][cur.y] == '.' && cur.cnt + 1 < v[cur.x + 1][cur.y])
            {
                q.push(node(cur.x + 1, cur.y, cur.cnt + 1));
                v[cur.x + 1][cur.y] = cur.cnt + 1;
            };
            if (cur.y > 0 && maze[cur.x][cur.y - 1] == '.' && cur.cnt + 1 < v[cur.x][cur.y - 1])
            {
                q.push(node(cur.x, cur.y - 1, cur.cnt + 1));
                v[cur.x][cur.y - 1] = cur.cnt + 1;
            };
            if (cur.y < n - 1 && maze[cur.x][cur.y + 1] == '.' && cur.cnt + 1 < v[cur.x][cur.y + 1])
            {
                q.push(node(cur.x, cur.y + 1, cur.cnt + 1));
                v[cur.x][cur.y + 1] = cur.cnt + 1;
            };
        };
        return -1;
    }
};