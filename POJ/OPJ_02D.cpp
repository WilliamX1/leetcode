#include <iostream>

using namespace std;

int f(int a, int b) //��ʾa�ò�����b�����ӽ��зֽ�ʱ�ķ�����
{
    if (a == 1) return 1;  //һ�ַֽ����
    if (b == 1) return 0;  //ĳ��������������
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
