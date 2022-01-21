#include <iostream>
#include <cstring>
#include <math.h>
using namespace std;

int B[100010];
int main()
{

    int n; cin >> n;

    if (n == 1) {cout << 2; return 0;};
    if (n == 2) {cout << 4; return 0;};

    int i, j;
    for (i = n;; i--)
    {
        for (j = 2; j <= sqrt(i + 1) && (i % j) != 0; j++);
        if (j > sqrt(i + 1)){ cout << 2 * i; return 0; };
    }

    /*int B_xb = 2, tmp;
    B[1] = 2; B[2] = 3;

    for (i = 5; i <= n; i++)
    {
        for (j = 1; j <= B_xb && (i % B[j]) != 0; j++);
        if (j > B_xb) B[++B_xb] = i;
    }
    cout << B[1] * B[B_xb];

    int sum = B_xb;

    for (i = n + 1; sum > 0; i++)
    {
        for (j = 1; j <= B_xb; j++)
            if (B[j] > 0 && (i % B[j]) == 0)
            { sum--; B[j] = -B[j];}
    }
    cout << B[1] * B[B_xb];*/


    return 0;
}
