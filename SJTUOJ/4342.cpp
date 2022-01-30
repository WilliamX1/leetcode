#include <iostream>

using namespace std;

long long int Mod = 1000000007;

int power(long long int a, long long int b)
{
    long long int res = 1;
    a %= Mod;
    while(b)
    {
        if (b & 1)
            res = (res * a) % Mod;
        a = (a * a) % Mod;
        b >>= 1;
    }
    return res % Mod;
}

int main()
{
    long long int n; cin >> n;

    long long int res = power(2, n - 1);
    res *= n;
    res %= Mod;
    cout << res;
    return 0;
}
