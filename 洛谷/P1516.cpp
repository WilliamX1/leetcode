#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long int x, y, m, n, L; cin >> x >> y >> m >> n >> L;

    long long int sum = x - y;
    long long int m_n = m - n; m_n %= L;

    for (long long int t = 0; t <= 10000000; t++)
    {
        sum %= L;
        if (sum == 0) { cout << t; return 0;}
        sum += m_n;
    }
    cout << "Impossible";
    return 0;
}
