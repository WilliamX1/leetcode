#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

int B[128];

int main()
{
    int N; scanf("%d", &N);
    for (int i = 1; i < N; i++)
        scanf("%d", &B[i]);
    int sum = 0;
    sum += B[1] + B[N - 1];

    for (int i = 1; i < N; i++)
        sum += min(B[i], B[i + 1]);
    printf("%d", sum);
    return 0;
}
