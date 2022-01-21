#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;

int A[100010];
int n, m, b;
int bsearch(int b){
    int left = 1, right = n, mid;
    while(left <= right){
        mid = (left + right) >> 1;
        if (A[mid] < b) left = mid + 1;
        else right = mid - 1;
    }
    if (left > n)
        return -1;
    else return A[left];
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);

    while(m--){
        scanf("%d", &b);
        printf("%d ", bsearch(b));
    }

    return 0;
}
