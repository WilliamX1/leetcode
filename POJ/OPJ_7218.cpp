#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

char A[210][210];
int MIN;

void Dfs(int x, int y, int steps)
{
    if (steps >= MIN) return;  //ºÙ ˜÷ß
    if (A[x][y] == 2) { MIN = min(MIN, steps); return;}

    A[x][y] = (-1) * A[x][y];
    if (A[x][y + 1] > 0) Dfs(x, y + 1, steps + 1); //Õ˘”“
    if (A[x + 1][y] > 0) Dfs(x + 1, y, steps + 1); //Õ˘œ¬
    if (A[x][y - 1] > 0) Dfs(x, y - 1, steps + 1); //Õ˘◊Û
    if (A[x - 1][y] > 0) Dfs(x - 1, y, steps + 1); //Õ˘…œ

    A[x][y] = (-1) * A[x][y];
    return;
}

struct node
{
    int x;
    int y;
    int steps;
    node(int the_x, int the_y, int the_steps)
    :x(the_x), y(the_y), steps(the_steps){};
};
int Bfs(int x, int y)
{
    queue<node> B;
    B.push(node(x, y, 0));

    node cur(-1, -1, '0');

    while(!B.empty())
    {

        cur = B.front();
        B.pop();
        if (A[cur.x][cur.y] == 'E') return cur.steps;

        A[cur.x][cur.y] = '#';

        if (A[cur.x - 1][cur.y] != '#') B.push(node(cur.x - 1, cur.y, cur.steps + 1));
        if (A[cur.x + 1][cur.y] != '#') B.push(node(cur.x + 1, cur.y, cur.steps + 1));
        if (A[cur.x][cur.y - 1] != '#') B.push(node(cur.x, cur.y - 1, cur.steps + 1));
        if (A[cur.x][cur.y + 1] != '#') B.push(node(cur.x, cur.y + 1, cur.steps + 1));
    }
    return -1;
}
int main()
{
    int T; cin >> T;

    for (int k = 1; k <= T; k++)
    {
        char ch;
        int R, C; cin >> R >> C;
        int start_x, start_y;


        MIN = 0;

        for (int i = 1; i <= R; i++)
            A[i][0] = A[i][C + 1] = '#';
        for (int i = 1; i <= C; i++)
            A[0][i] = A[R + 1][C] = '#';

        for (int i = 1; i <= R; i++)
        {
            for (int j = 1; j <= C; j++)
            {
                cin >> A[i][j];
                if (A[i][j] == 'S') { start_x = i; start_y = j;}
                /*if (ch == '#') A[i][j] = 0;
                else if (ch == '.') A[i][j] = 1;
                else if (ch == 'S')
                { start_x = i; start_y = j;}
                else if (ch == 'E') A[i][j] = 2;*/
            }
        }

        /*Dfs(start_x, start_y, 0);

        if (MIN == 1e9) printf("%s\n", "oop!");
        else printf("%d\n", MIN); */

        MIN = Bfs(start_x, start_y);
        if (MIN == -1) cout << "oop!" << endl;
        else cout << MIN << endl;
    }

    return 0;
}
