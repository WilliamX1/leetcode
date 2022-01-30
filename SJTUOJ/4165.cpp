#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

long long int A[100010];

int main()
{
    int N; scanf("%d", &N);

    A[0] = 0; A[N + 1] = 0;
    for (int i = 1; i <= N; i++) scanf("%lld", &A[i]);

    long long int tmp;
    for (int i = 1; i <= N; i++)
    {
        scanf("%lld", &tmp);
        A[i] -= tmp;
    }

    long long int sum = 0;
    for (int i = 0; i <= N; i++)
    {
        if (A[i] * A[i - 1] <= 0)
            sum += abs(A[i]);
        else
        {
            if (A[i] > 0 && A[i - 1] > 0)
                sum += A[i] > A[i - 1] ? A[i] - A[i - 1] : 0;
            else if (A[i] < 0 && A[i - 1] < 0)
                sum += A[i] < A[i - 1] ? A[i - 1] - A[i] : 0;
        }
    }
    cout << sum;
    return 0;
}
