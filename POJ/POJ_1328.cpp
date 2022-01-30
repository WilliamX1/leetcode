#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

struct line
{
    double left;
    double right;
};
line A[1010];
bool myCompare(line A, line B){return A.left < B.left;};
int main()
{
    int n, i = 0;
    double d, x, y; cin >> n >> d;

    while(n != 0 || d != 0)
    {
        bool flag = true;

        for (int i = 1; i <= n; i++)
        {
            cin >> x >> y;
            if (y > d) { flag = false; continue;}
            A[i].left = x - sqrt(d * d - y * y);
            A[i].right = x + sqrt(d * d - y * y);
        }
        if (!flag) cout << "Case " << ++i << ": " << -1 << endl;
        else
        {
            int sum = 1;

            sort(A + 1, A + n + 1, myCompare);
            x = A[1].left; y = A[1].right;

            for (int i = 2; i <= n; i++)
            {
                if (A[i].left > y)
                {
                    x = A[i].left;
                    y = A[i].right;
                    ++sum;
                }
                else y = min(y, A[i].right);
            }
            cout << "Case " << ++i << ": " << sum << endl;
        }
    cin >> n >> d;
    }

    return 0;
}
