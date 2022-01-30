#include <iostream>
#include <stdio.h>
using namespace std;

int A[10010];

int main()
{
    int N, M, K; scanf("%d%d", &N, &M);
    A[0] = 0;
    for (int i = 1; i <= N; i++) scanf("%d", &A[i]);
    for (int i = 1; i <= N; i++) A[i] += A[i - 1];

    while(M--){
        scanf("%d", &K);
        int res = 0;
        for (int cur = N; cur - K >= 0; cur--)
            res = max(res, A[cur] - A[cur - K]);
        printf("%d\n", res);
    }
    return 0;
}
