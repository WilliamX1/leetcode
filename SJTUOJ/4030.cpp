#include <iostream>
#include <queue>
#include <stdio.h>
#include <memory.h>
using namespace std;

double A[1000010];
double B[1000010];
double C[1000010];

struct node
{
    int num;  //第几枪
    int ses;  //连续次数
    double pro;  //击中概率
    node(int n, int s, double p):num(n),ses(s),pro(p){};
};
int main()
{
    int N; scanf("%d", &N);

    memset(A, 0, sizeof(A));
    for (int i = 1; i <= N; i++) cin >> A[i];

    /*queue<node> q;
    q.push(node(1, 1, A[1]));
    q.push(node(1, 0, 1 - A[1]));

    int num, ses;
    double sum = 0;
    while(!q.empty())
    {
        num = q.front().num; if (num > N) { q.pop(); continue;};

        ses = q.front().ses;

        q.push(node(num + 1, ses + 1, A[num + 1] * q.front().pro));  //下一枪继续击中
        q.push(node(num + 1, 0, (1 - A[num + 1]) * q.front().pro));  //下一枪没有击中

        if (q.front().ses != 0)
            sum += (2 * q.front().ses - 1) * q.front().pro;
        q.pop();
    }
    printf("%.6f ", sum);*/

    B[0] = C[0] = 0;
    for (int i = 1; i <= N; i++)
    {
        B[i] = (B[i - 1] + 1) * A[i - 1] + 1;
        C[i] = C[i - 1] + B[i] * A[i];
    }

    printf("%.6f", C[N]);

    return 0;
}
