#include <iostream>
#include <algorithm>
using namespace std;

long long int A[100010];
long long int B[100010];

int main()
{
    int n; scanf("%d",&n);
    for (int i = 0; i < n; i++)
        scanf("%lld",&A[i]);

    sort(A, A + n);

    for (int i = 1; i < n; i++)
        B[i] = A[i] - A[i - 1];

    long long int sum = 0;
    for (int i = 1; i < n; i++)
        sum += B[i] * (n - i) * i;

    sum %= 1000000007;
    cout << sum;
    return 0;
}
