#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n, k, A, B; cin >> n >> k >> A >> B;
    long long res = 0;
    if (k == 1){
        cout << (n - 1) * A;
        return 0;
    }
    while(n != 1){
        if (n < k) res += A * (n - 1), n = 1;
        else if(n % k != 0)
            res += A * (n - (n / k) * k), n = (n / k) * k;
        else{
            res += min(B, A * (n - n / k));
            n /= k;
        }
    }
    cout << res;
    return 0;
}
