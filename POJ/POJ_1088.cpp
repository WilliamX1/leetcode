#include <iostream>
#include <algorithm>
using namespace std;

struct node
{
    int x;
    int y;
    int sum;
    int h;
};
node A[12100];  //A中存放最大值
int B[110][110];  //B中存放高度

bool myCompare(node A, node B){return A.h < B.h;};
int main()
{
    int R, C; cin >> R >> C;
    int num, MAX = 0;
    for (int i = 1; i <= R; i++)
        for (int j = 1; j <= C; j++)
             {
                cin >> B[i][j];
                num = (i - 1) * C + j;
                A[num].x = i; A[num].y = j; A[num].sum = 1;
                A[num].h = B[i][j];
             }
    for (int i = 0; i <= 101; i++)
        B[0][i] = B[R + 1][i] = B[i][0] = B[i][C + 1] = -2e9; //设置为无限低

    sort(A + 1, A + R * C + 1, myCompare);  //对点进行排序

    for (int i = 1; i <= R * C; i++)
    {
        int cur_H = B[A[i].x][A[i].y];  //当前点的高度
        int cur_sum = A[(A[i].x - 1) * C + A[i].y].sum;  //当前点的最大值
        if (B[A[i].x - 1][A[i].y] > cur_H)  //左
            A[(A[i].x - 1 - 1) * C + A[i].y].sum = max(A[(A[i].x - 1 - 1) * C + A[i].y].sum, 1 + cur_sum);
        if (B[A[i].x + 1][A[i].y] > cur_H)  //右
            A[(A[i].x + 1 - 1) * C + A[i].y].sum = max(A[(A[i].x + 1 - 1) * C + A[i].y].sum, 1 + cur_sum);
        if (B[A[i].x][A[i].y - 1] > cur_H)  //下
            A[(A[i].x - 1) * C + A[i].y - 1].sum = max(A[(A[i].x - 1) * C + A[i].y - 1].sum, 1 + cur_sum);
        if (B[A[i].x][A[i].y + 1] > cur_H)  //上
            A[(A[i].x - 1) * C + A[i].y + 1].sum = max(A[(A[i].x - 1) * C + A[i].y + 1].sum, 1 + cur_sum);
    }
    for (int i = 1; i <= R * C; i++)
        MAX = max(MAX, A[i].sum);
    cout << MAX;
    return 0;
}
