#include <iostream>

using namespace std;

int A[100];
int B[100];

int main()
{
    int N, NA, NB; scanf("%d%d%d", &N, &NA, &NB);

    for (int i = 1; i <= NA; i++) scanf("%d", &A[i]);
    for (int i = 1; i <= NB; i++) scanf("%d", &B[i]);
    A[0] = A[NA]; B[0] = B[NB];

    int a, b;
    int winA = 0, winB = 0;
    for (int i = 1; i <= N; i++)
    {
        a = A[i % NA];
        b = B[i % NB];
        if (a == 0)
        {
            if (b == 2) winA++;
            else if (b == 5) winB++;
        }
        else if (a == 2)
        {
            if (b == 0) winB++;
            else if (b == 5) winA++;
        }
        else if (a == 5)
        {
            if (b == 0) winA++;
            else if (b == 2) winB++;
        }
    }

    if (winA > winB) printf("%c", 'A');
    else if (winA < winB) printf("%c", 'B');
    else if (winA == winB) printf("%s", "draw");

    return 0;
}
