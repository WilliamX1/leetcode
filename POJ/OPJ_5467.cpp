#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;

struct node
{
    int a;
    int b;
};

const int N = 1000;
node A[N + 1];

bool myCompare(node A, node B){return A.b > B.b;};

int main()
{
    int a, b;
    int n; scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        memset(A, 0, sizeof(A));
        int A_xb = 0;

        for (int j = 1; j <= 2; j++)
        {
            scanf("%d%d", &a, &b);
            while(b >= 0)
            {
                ++A_xb;
                A[A_xb].a = a;
                A[A_xb].b = b;
                scanf("%d%d", &a, &b);
            }
        }
        sort(A + 1, A + A_xb + 1, myCompare);
        for (int j = 1; j <= A_xb; j++)
        {
            int tmp = A[j].a;
            int k;
            for (k = j + 1; k <= A_xb && A[j].b == A[k].b; k++)
                tmp += A[k].a;
            if (tmp != 0) printf("%c %d %d %c ", '[', tmp, A[j].b, ']');
            j = k - 1;
        }
        printf("\n");
    }
    return 0;
}
