#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int A[1010];

int main()
{
    int N, K; cin >> N >> K;

    for (int i = 1; i <= N; i++) scanf("%d", &A[i]);
    A[0] = -1e9;

    sort(A + 1, A + N + 1);

    int MAX = -1;
    int i, j(N);
    for (i = 1; i < j; i++)
    {
        for (;j > i && A[i] + A[j] > K; j--);
        MAX = max(MAX, A[i] + A[j]);
    }

    printf("%d", MAX);

    return 0;
}
