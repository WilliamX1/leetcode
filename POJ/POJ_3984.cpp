#include <iostream>

using namespace std;

struct node
{
    int x;
    int y;
};
int maze[5][5];
node A[50];
int xb = 0;

bool Dfs(int x, int y)
{
    if (x == 4 && y == 4) return true;
    if (x < 0 || x >= 5 || y < 0 || y >= 5) return false;
    if (maze[x][y] == 1) return false;

    if (Dfs(x, y + 1)) { xb++; A[xb].x = x; A[xb].y = y + 1; return true;}
    if (Dfs(x + 1, y)) { xb++; A[xb].x = x + 1; A[xb].y = y; return true;}
    if (Dfs(x - 1, y)) { xb++; A[xb].x = x - 1; A[xb].y = y; return true;}
    if (Dfs(x, y - 1)) { xb++; A[xb].x = x; A[xb].y = y - 1; return true;}

}
int main()
{
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            cin >> maze[i][j];

    Dfs(0, 0); xb++; A[xb].x = 0; A[xb].y = 0;

    for (int i = xb; i >= 1; i--)
        cout << "(" << A[i].x << ", " << A[i].y << ")" << endl;
    return 0;
}
