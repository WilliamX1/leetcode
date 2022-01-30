#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int A[110][110];
struct node
{
    int x;
    int y;
    int label;
    node(int t_x, int t_y, int t_l)
    :x(t_x), y(t_y), label(t_l){};
    node(){};
};

int main()
{
    int L; cin >> L;
    int need = 0;

    queue<node> q;

    //初始化
    for (int i = 0; i <= L + 1; i++)
        A[0][i] = A[L + 1][i] = A[i][0] = A[i][L + 1] = 1;

    for (int i = 1; i <= L; i++)
        for (int j = 1; j <= L; j++)
        {
            cin >> A[i][j];
            if (A[i][j] == 0) ++need;
            else if (A[i][j] == 1) q.push(node(i, j, 1));;
        }

    //求解
    node cur;
    while(need > 0)
    {
        cur = q.front();
        q.pop();
        if (A[cur.x - 1][cur.y] == 0)
        {
            q.push(node(cur.x - 1, cur.y, cur.label + 1));
            A[cur.x - 1][cur.y] = 1;
            need--;
        }
        if (A[cur.x + 1][cur.y] == 0)
        {
            q.push(node(cur.x + 1, cur.y, cur.label + 1));
            A[cur.x + 1][cur.y] = 1;
            need--;
        }
        if (A[cur.x][cur.y - 1] == 0)
        {
            q.push(node(cur.x, cur.y - 1, cur.label + 1));
            A[cur.x][cur.y - 1] = 1;
            need--;
        }
        if (A[cur.x][cur.y + 1] == 0)
        {
            q.push(node(cur.x, cur.y + 1, cur.label + 1));
            A[cur.x][cur.y + 1] = 1;
            need--;
        }
    }
    cout << cur.label;

    return 0;
}
