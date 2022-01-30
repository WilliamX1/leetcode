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
node A[12100];  //A�д�����ֵ
int B[110][110];  //B�д�Ÿ߶�

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
        B[0][i] = B[R + 1][i] = B[i][0] = B[i][C + 1] = -2e9; //����Ϊ���޵�

    sort(A + 1, A + R * C + 1, myCompare);  //�Ե��������

    for (int i = 1; i <= R * C; i++)
    {
        int cur_H = B[A[i].x][A[i].y];  //��ǰ��ĸ߶�
        int cur_sum = A[(A[i].x - 1) * C + A[i].y].sum;  //��ǰ������ֵ
        if (B[A[i].x - 1][A[i].y] > cur_H)  //��
            A[(A[i].x - 1 - 1) * C + A[i].y].sum = max(A[(A[i].x - 1 - 1) * C + A[i].y].sum, 1 + cur_sum);
        if (B[A[i].x + 1][A[i].y] > cur_H)  //��
            A[(A[i].x + 1 - 1) * C + A[i].y].sum = max(A[(A[i].x + 1 - 1) * C + A[i].y].sum, 1 + cur_sum);
        if (B[A[i].x][A[i].y - 1] > cur_H)  //��
            A[(A[i].x - 1) * C + A[i].y - 1].sum = max(A[(A[i].x - 1) * C + A[i].y - 1].sum, 1 + cur_sum);
        if (B[A[i].x][A[i].y + 1] > cur_H)  //��
            A[(A[i].x - 1) * C + A[i].y + 1].sum = max(A[(A[i].x - 1) * C + A[i].y + 1].sum, 1 + cur_sum);
    }
    for (int i = 1; i <= R * C; i++)
        MAX = max(MAX, A[i].sum);
    cout << MAX;
    return 0;
}
