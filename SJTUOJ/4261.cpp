#include <iostream>

using namespace std;
long long A[1000010];

int main()
{
    int n, m, tmp; cin >> n >> m;
    char ch;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            cin >> ch;
            if ('a' <= ch && ch <= 'z') tmp = ch - 'a' + 1;
            else tmp = ch - 'A' + 1;

            if (i & 1) A[m * (i - 1) + j] = tmp;
            else A[m * i - j + 1] = tmp;
        }
    //for (int i = 1; i <= n * m; i++)
        //cout << A[i] << " ";

    int steps[1000010], x = 0, len = n * m;
    steps[1] = 1;
    for (int i = 2; steps[i - 1] <= len; i++)
        x++, steps[i] = steps[i - 1] + x;

    long long res = 1, mod = 1e9 + 7;
    for (int i = 1; steps[i] <= len; i++)
        res = (A[steps[i]] * res) % mod;
    cout << res;
    return 0;
}
