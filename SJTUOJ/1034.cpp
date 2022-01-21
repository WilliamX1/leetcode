#include <iostream>

using namespace std;

int A[200010];
int main()
{
    int N, K; scanf("%d%d", &N, &K);

    for (int i = 1; i <= N; i++)
        scanf("%d", &A[i]);
    for (int i = 1; i < K; i++)
        A[N + i] = A[i];

    int last = 0;
    for (int i = 1; i <= K; i++)
        if (A[i] > last) last = A[i];

    int MIN = last;
    for (int i = 1; i < N; i++)
    {
        if (last != A[i])
        {
            if (A[i + K] > last) last = A[i + K];
            if (last < MIN) MIN = last;
        }
        else
        {
            last = A[i + 1];
            for (int j = 1; j < K; j++)
                if (A[j + i + 1] > last) last = A[j + i + 1];
            if (last < MIN) MIN = last;
        }
    }
    cout << MIN;
    /*for (int i = 2; i <= K; i++)
        for (int j = 1; j <= N + K - i; j++)
            if (A[j] < A[j + 1]) A[j] = A[j + 1];

    int MIN = 1e9;
    for (int i = 1; i <= N; i++)
        if (A[i] < MIN) MIN = A[i];
    printf("%d", MIN);*/

    return 0;
}
