#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long int a, b, c; cin >> a >> b >> c;

    if (a > b)
    {
        b += c;
        if (b > a)
            a = b = (a + b) / 2;
    }
    else
    {
        a += c;
        if (a > b)
            a = b = (a + b) / 2;
    }
    c = min(a, b);

    long long int res = sqrt(2 * c);

    while(res * (res + 1) / 2 > c)
        res--;
    cout << res;

    return 0;
}
