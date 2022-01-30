#include <iostream>
#include <memory.h>
using namespace std;

char A[10][10];

bool row[10];  //代表各行状态
bool colume[10];  //代表各列状态
int total;
int n, k;

void Dfs(int x, int y, int sum)
{
    if (sum == k) {++total; return;};

    row[x] = colume[y] = 1;

    for (int i = x + 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (A[i][j] == '#' && row[i] == 0 && colume[j] == 0)
                { Dfs(i, j, sum + 1); row[i] = colume[j] = 0;};
    row[x] = colume[y] = 0;
}

int main()
{
    cin >> n >> k;

    while(n != -1 || k != -1)
    {
        memset(row, 0, sizeof(row));
        memset(colume, 0, sizeof(colume));
        total = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                cin >> A[i][j];
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (A[i][j] == '#')
                    {
                        Dfs(i, j, 1);
                    }
        cout << total << endl;
        cin >> n >> k;
    }
    return 0;
}
