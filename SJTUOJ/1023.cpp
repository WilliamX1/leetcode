#include <iostream>

using namespace std;
int A[610][610];
int main()
{
    int n; cin >> n;
    int a, b;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", &a, &b);
        for (int j = 1; j <= a; j++)
            for (int k = 1; k <= a; k++)
                scanf("%d", &A[j][k]);
        if (b == 0)
            for (int j = 1; j <= a; j++)
            {
                for (int k = a; k >= 1; k--)
                    printf("%d ", A[j][k]);
                printf("\n");
            }
        else if (b == 1)
            for (int j = a; j >= 1; j--)
            {
                for (int k = 1; k <= a; k++)
                    printf("%d ", A[j][k]);
                printf("\n");
            }
        else if (b == 2)
            for (int j = 1; j <= a; j++)
            {
                for (int k = 1; k <= a; k++)
                    printf("%d ", A[k][j]);
                printf("\n");
            }



    }
    return 0;
}
