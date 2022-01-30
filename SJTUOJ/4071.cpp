#include <iostream>

using namespace std;

long long int Mod = 1000000000 + 7;
long long int tempA, tempB, tempC, tempD;
void func(long long int n, long long int &a, long long int &b, long long int &c, long long int &d)
{
    if (n == 1){
        a = 0;
        b = c = d = 1;
        return;
    }
    if (n % 2 == 0)
    {
        func(n/2, a, b, c, d);
        tempA = a * a + b * c;
        tempB = b * (a + d);
        tempC = c * (a + d);
        tempD = c * b + d * d;
        a = tempA % Mod;
        b = tempB % Mod;
        c = tempC % Mod;
        d = tempD % Mod;
        return;
    }
    else
    {
        func(n/2, a, b, c, d);
        tempA = b * (a + d);
        tempB = a * a + b * (a + c + d);
        tempC = c * b + d * d;
        tempD = c * (a + b + d) + d * d;
        a = tempA % Mod;
        b = tempB % Mod;
        c = tempC % Mod;
        d = tempD % Mod;
        return;
    }
}
int main()
{
    long long int n; cin >> n; n++;
    long long int a, b, c, d;

    if (n <= 2) { cout << 1; return 0;}

    n -= 2;
    func(n, a, b, c, d);
    cout << (b + d) % Mod << endl;
    return 0;
}
