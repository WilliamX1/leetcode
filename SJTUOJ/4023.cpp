#include <iostream>
#include <stdio.h>

using namespace std;
int A[128];

int main()
{
    int n; cin >> n;
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);

    for (int i = 1; i <= n; i++)
    {
        int res = 0;
        for (int j = 1; j < i; j++)
            if (A[j] < A[i]) res++;
        printf("%d ", res);
    }
    return 0;
}
