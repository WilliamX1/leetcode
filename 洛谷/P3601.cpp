#include <bits/stdc++.h>

using namespace std;
const int N = 1000000 + 10;
long long Prime[N];
bool Check[N];
bool isPrime[N];
long long tot = 0;
long long L, R;
long long res = 0;
const int Mod = 666623333;

void getPrime()
{
    for (long long i = 2; i < N; i++)
    {
        if (!Check[i])
            Prime[++tot] = i;
        for (long long j = 1; j <= tot; j++)
        {
            if (i * Prime[j] > N)
                break;
            Check[i * Prime[j]] = true;
            if (i % Prime[j] == 0)
                break;
        }
    }
}
void getPhi()
{
    for (int i = 1; i <= tot; i++)
    {
        long long start;
        if (L / Prime[i] <= 1)
            start = 2 * Prime[i];
        else
        {
            start = L / Prime[i];
            while(start < L) start += Prime[i];
        }
        long long End;
        if (R / Prime[i] <= 1)
            End = 2 * Prime[i];
        else
        {
            End = R / Prime[i];
            while(End < R) End += Prime[i];
        }
        res += (End - start) / Prime[i];
        res %= Mod;
    }
}
int main()
{
    cin >> L >> R;
    getPrime();
    getPhi();
    cout << res;
    return 0;
}
