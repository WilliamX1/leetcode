#include <iostream>
#include <memory.h>
using namespace std;
int board[30][30];
struct node
{
    char ch;
    int num;
};
node road[100];
int xb = 0;
int N, p, q;

bool Dfs(int x, int y, int total)
{
    if (x <= 0 || x > p || y <= 0 || y > q) return false;
    if (board[x][y] == 1) return false;
    if (total == N) return true;

    board[x][y] = 1;

    if (Dfs(x - 1, y - 2, total + 1)) {++xb; road[xb].ch = y - 2 + 'A' - 1; road[xb].num = x - 1; return true;}
    if (Dfs(x + 1, y - 2, total + 1)) {++xb; road[xb].ch = y - 2 + 'A' - 1; road[xb].num = x + 1; return true;}
    if (Dfs(x - 2, y - 1, total + 1)) {++xb; road[xb].ch = y - 1 + 'A' - 1; road[xb].num = x - 2; return true;}
    if (Dfs(x + 2, y - 1, total + 1)) {++xb; road[xb].ch = y - 1 + 'A' - 1; road[xb].num = x + 2; return true;}
    if (Dfs(x - 2, y + 1, total + 1)) {++xb; road[xb].ch = y + 1 + 'A' - 1; road[xb].num = x - 2; return true;}
    if (Dfs(x + 2, y + 1, total + 1)) {++xb; road[xb].ch = y + 1 + 'A' - 1; road[xb].num = x + 2; return true;}
    if (Dfs(x - 1, y + 2, total + 1)) {++xb; road[xb].ch = y + 2 + 'A' - 1; road[xb].num = x - 1; return true;}
    if (Dfs(x + 1, y + 2, total + 1)) {++xb; road[xb].ch = y + 2 + 'A' - 1; road[xb].num = x + 1; return true;}

    board[x][y] = 0;
    return false;
}

int main()
{
    int t; cin >> t;
    int r_xb = 0;
    for (int k = 1; k <= t; k++)
    {
        cin >> p >> q;
        N = p * q; //总共要走过多少格子

        cout << "Scenario #" << k << ":" << endl;
        bool flag = true;

        for (int i = 1; i <= p && flag; i++)
            for (int j = 1; j <= q; j++)
            {
                memset(board, 0, sizeof(board));
                xb = 1;
                road[xb].ch = i + 'A' - 1;
                road[xb].num = j;

                if (Dfs(i, j, 1))
                {

                    cout << road[1].ch << road[i].num;
                    for (int i = xb; i > 1; i--)
                         cout << road[i].ch << road[i].num;
                    cout << endl;
                    flag = false;
                    break;
                }
             }
        if (flag) cout << "impossible" << endl;
        cout << endl;
    }

    return 0;
}
