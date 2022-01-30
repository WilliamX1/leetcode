#include <iostream>
#include <algorithm>
using namespace std;

int M;
int A[10010];

int divide(int l, int r)
{
    int mid = A[l];

    do
    {
        while(l < r && A[r] >= mid) --r;
        if (l < r) {A[l] = A[r]; ++l;};
        while(l < r && A[l] <= mid) ++l;
        if (l < r) {A[r] = A[l]; --r;};
    }while(l < r);

    A[l] = mid;
    return l;
}

int quickSort(int l, int r)
{
    if (l == r) return A[l];

    int mid = divide(l, r);

    if (mid == M) return A[mid];
    else if (mid > M) return quickSort(l, mid - 1);
    else if (mid < M) return quickSort(mid + 1, r);
}

int main()
{
    int N; scanf("%d", &N);

    for (int i = 1; i <= N; i++)
        scanf("%d", &A[i]);

    M = (N + 1) / 2;

    sort(A + 1, A + N + 1);
    cout << A[M];
    //cout << quickSort(1, N);

    return 0;
}
