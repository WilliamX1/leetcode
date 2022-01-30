#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int A[1030][1030];

int main()
{
    int d, n; cin >> d >> n;
    int x, y, t;
    int x_t, x_b, y_t, y_b;
    int MAX = 0;
    int sum = 1;

    memset(A, 0, sizeof(A));

    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d%d", &x, &y, &t);
        x_b = max(0, x - d);
        x_t = min(1024, x + d);
        y_b = max(0, y - d);
        y_t = min(1024, y + d);
        for (int j = x_b; j <= x_t; j++)
            for (int k = y_b; k <= y_t; k++)
            {
                A[j][k] += t;
                if (A[j][k] == MAX) ++sum;
                if (A[j][k] > MAX)
                {
                    sum = 1;
                    MAX = A[j][k];
                }
            }
    }
    cout << sum << " " << MAX;
    return 0;
}
