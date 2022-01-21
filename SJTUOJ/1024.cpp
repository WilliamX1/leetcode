#include <iostream>
#include <algorithm>
using namespace std;
int A[10010];

int main()
{
    int n; cin >> n;
    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);
    sort(A, A + n);
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    return 0;
}
