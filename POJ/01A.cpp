#include <iostream>
#include <cstdio>
#include <vector>
#include <memory.h>
//线性筛
using namespace std;

const long long N = 1e5;

bool sieve[N];

int prime[100010];

void linear_sieve()
{
    int prime_xb = -1;

    for (int i = 2; i < N; i++)
    {
        if (!sieve[i]) prime[++prime_xb] = i;  //生成质数表

        for (int j = 0; i * prime[j] < N; j++)
        {
            sieve[i * prime[j]] = true;  //除去质数倍

            if (i % prime[j] == 0) break;
        }
    }
    //for (int i = 0; i <= prime_xb; i++)
        //cout << prime[i] << " ";
}

bool is(int x)
{
    if (sieve[x] == true) return false;

    int tmp[8], tmp_xb = 0;
    while(x > 0)
    {
        tmp[++tmp_xb] = x % 10;
        x /= 10;
    }

    int y = 0;
    for (int i = 1; i <= tmp_xb; i++)
        y = y * 10 + tmp[i];
    if (sieve[y] == true) return false;

    return true;
}

int main()
{
    memset(prime, 0, sizeof(prime));
    linear_sieve();

    int M, N; cin >> M >> N;

    int i;
    bool flag = true;

    for (i = M; i <= N; i++)
        if (is(i)) { cout << i; flag = false; break;};

    for (i++; i <= N; i++)
        if (is(i)) { cout << "," << i; flag = false;};

    if (flag) cout << "No";
    return 0;
}
