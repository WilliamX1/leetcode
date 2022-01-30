#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

int A[100010];
long long int n, k;
bool myCompare(long long int A, long long int B){return A > B;};
bool check(long long int mid)
{
    long long int sum = 0;
    for (int i = 1; i <= n && A[i] > mid; i++)
    {
        sum += (A[i] - mid - 1) / (k - 1) + 1;
        if (sum > mid) return false;
    }
    return true;
}
int main()
{
    cin >> n;
    long long int l = 1, r = 1;
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &A[i]);
        if (A[i] > r) r = A[i];
    }
    cin >> k;

    if (k == 1) { cout << r; return 0;}

    sort(A + 1, A + n + 1, myCompare);

    long long int mid = 0;
    while(l <= r)
    {
        mid = (l + r) / 2;
        if (check(mid)) r = mid - 1;
        else l = mid + 1;
    }
    cout << l;
    return 0;
}
