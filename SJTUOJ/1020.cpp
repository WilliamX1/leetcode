#include <iostream>
#include <math.h>
using namespace std;

int A[100010];

int main()
{
    int A_xb = -1;
    A[++A_xb] = 2;

    int i, j;
    int N; cin >> N;

    for (i = 3; i <= sqrt(N) + 2; i++)
    {
        for (j = 0; j <= A_xb && (i % A[j]) != 0; j++);
        if (j > A_xb) A[++A_xb] = i;
    }


    int sum = 0; cout << N << "=";

    for (int i = 0; i <= A_xb; i++)
    {
        if (N % A[i] == 0)
        {
            if (sum == 0)
                cout << A[i];
            sum++;
            N /= A[i];
            i--;
        }
        else if (sum != 0)
        {
            cout << "(" << sum << ")";
            sum = 0;
        }
    }

    if (N != 1) cout << N << "(1)";
    return 0;
}
