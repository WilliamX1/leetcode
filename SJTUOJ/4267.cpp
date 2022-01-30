#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;
int A[100010];

int main()
{
    int n, m, k; scanf("%d%d", &n, &m);

    A[0] = 0;
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    for (int i = 1; i <= n; i++) A[i] += A[i - 1];

    while(m--){
        scanf("%d", &k);
        int left = 1, right = n, mid;

        while(left <= right){
            mid = (left + right) >> 1;
            if (A[mid] < k) left = mid + 1;
            else right = mid - 1;
        }
        printf("%d %d\n", left, k - A[left - 1]);
    }
    return 0;
}
