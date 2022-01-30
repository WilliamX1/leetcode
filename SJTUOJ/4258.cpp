#include <iostream>

using namespace std;
const int mod = 2019;
int fastPower(int base, int k){
    int res = 1;

    while(k){
        if (k & 1)
            res = (res * base) % mod;
        base = (base * base) % mod;
        k >>= 1;
    }
    return res % mod;
}
int main()
{
    int a, n; cin >> a >> n;
    cout << fastPower(a, n);
    return 0;
}
