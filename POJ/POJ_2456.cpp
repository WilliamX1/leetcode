#include <iostream>
#include <algorithm>
using namespace std;

int A[100010];
int N, C;

bool check(int ans)
{
    int sum = 1;
    int last = A[1];

    for (int i = 2; i <= N; i++)
    {
        if (A[i] - last >= ans)
        {
            ++sum;
            last = A[i];
        }
        if (sum >= C) return true;
    }
    return false;
}
int main()
{
    scanf("%d%d", &N, &C);

    A[0] = 0;
    int l = 200000000, r = 0;
    for (int i = 1; i <= N; i++)
    {
        scanf("%d", &A[i]);
        l = min(l, A[i] - A[i - 1]);
    }
    sort(A + 1, A + N + 1);
    r = A[N] - A[1];
    int mid;

    while(l <= r)
    {
        mid = (l + r) / 2;
        if (check(mid)) l = mid + 1;
        else r = mid - 1;
    }
    cout << r;
    return 0;
}
