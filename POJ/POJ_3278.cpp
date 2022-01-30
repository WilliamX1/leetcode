#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

bool whether[100010];
struct node
{
    int x;  //坐标
    int steps; //目前所走的步数
    node(int xx, int s):x(xx), steps(s){};
};
queue<node> A;

int main()
{
    int N, K; cin >> N >> K;
    int tmp_x, tmp_steps;
    memset(whether, 0, sizeof(whether));

    A.push(node(N, 0)); whether[N] = 1;

    while(!A.empty())
    {
        tmp_x = A.front().x;
        tmp_steps = A.front().steps;

        if (tmp_x == K)
        { cout << tmp_steps; return 0;}
        if (tmp_x - 1 >= 0 && !whether[tmp_x - 1])
            { A.push(node(tmp_x - 1, tmp_steps + 1)); whether[tmp_x - 1] = 1;}
        if (tmp_x + 1 <= 100000 && !whether[tmp_x + 1])
            { A.push(node(tmp_x + 1, tmp_steps + 1)); whether[tmp_x + 1] = 1;}
        if (2 * tmp_x <= 100000 && !whether[2 * tmp_x])
            { A.push(node(2 * tmp_x, tmp_steps + 1)); whether[2 * tmp_x] = 1;}
        A.pop();
    }
    return 0;
}
