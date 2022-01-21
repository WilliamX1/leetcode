#include <iostream>
#include <stdio.h>
#include <memory.h>
using namespace std;

bool A[20010];

int main()
{
    memset(A, 0, sizeof(A));

    int N; scanf("%d", &N);
    int tmp;

    while(N--)
    {
        scanf("%d", &tmp);
        A[tmp] = 1;
    }

    for (int i = 1; i <= 20000; i++)
        if (A[i] == 0)
        {
            for (int j = i - 1; j >= i / 2; j--)
                if (A[j] == 1 && A[i - j] == 1)
                { A[i] = 1; break;}
        }
    A[0] = 1;

    int B[20010];
    int B_xb = 0;
    for (int i = 1; i <= 20000; i++)
        if (A[i] == 1) B[++B_xb] = i;

    int M; scanf("%d", &M);
    while(M--)
    {
        scanf("%d", &tmp);

        int i;
        for (i = 1; i <= B_xb; i++)
            if (A[tmp % B[i]] == 1)
            { printf("YES\n"); break;}
        if (i > B_xb) printf("NO\n");
    }

    return 0;
}
