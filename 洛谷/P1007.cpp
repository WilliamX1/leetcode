#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <cmath>
using namespace std;

int A[5010];
int main()
{
    int L, N; scanf("%d%d", &L, &N);

    memset(A, 0, sizeof(A));

    int tmp;
    int m = 0, M;
    int l = L + 1, r = 0;
    for (int i = 1; i <= N; i++)
    {
        scanf("%d", &tmp);
        A[tmp] = 1;

        m = max(m, min(tmp, L + 1 - tmp)); //��ȡ���м��
        l = min(l, tmp);  //�����
        r = max(r, tmp);  //���ұ�
    }
    M = max(L + 1 - l, r);

    printf("%d %d", m, M);

    return 0;
}
