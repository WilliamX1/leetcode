#include <iostream>

using namespace std;

int f(int a, int b) //表示a用不超过b的因子进行分解时的方案数
{
    if (a == 1) return 1;  //一种分解完成
    if (b == 1) return 0;  //某个子问题是质数
    if (a % b == 0) return f(a / b, b) + f(a, b - 1);
    return f(a, b - 1);
}

int main()
{
    int n; scanf("%d", &n);

    int m;
    while(n--)
    {
        scanf("%d", &m);
        printf("%d\n", f(m, m));
    }

    return 0;
}
