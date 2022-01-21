#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;
int roomsNum[60][60];
int roomsColor[60][60];
int roomSum = 0;
int roomMax = 0;
int roomArea = 0;

void Dfs(int i, int j)
{
    if (roomsColor[i][j] != 0)
        return;
    ++roomArea; roomsColor[i][j] = roomSum;
    if ((roomsNum[i][j] & 1) == 0) Dfs(i, j - 1);
    if ((roomsNum[i][j] & 2) == 0) Dfs(i - 1, j);
    if ((roomsNum[i][j] & 4) == 0) Dfs(i, j + 1);
    if ((roomsNum[i][j] & 8) == 0) Dfs(i + 1,j);
}
int main()
{
    int R, C; cin >> R >> C;
    memset(roomsColor, 0, sizeof(roomsColor));

    for (int i = 1; i <= R; i++)
        for (int j = 1; j <= C; j++)
            cin >> roomsNum[i][j];

    for (int i = 1; i <= R; i++)
        for (int j = 1; j <= C; j++)
        {
            if (roomsColor[i][j] == 0)
            {
                roomSum++; roomArea = 0;
                Dfs(i, j);
                roomMax = max(roomMax, roomArea);
            }
        }
    cout << roomSum << endl << roomMax;
    return 0;
}
