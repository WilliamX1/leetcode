#include <bits/stdc++.h>

using namespace std;

int A[5010];
long long int Mod = 1000000000 + 7;

int main()
{
    int n; cin >> n;

    memset(A, 0, sizeof(A));
    int tmp;
    while(n--)
    {
        cin >> tmp;
        A[tmp]++;
    }

    long long int sum = 0;
    for (int i = 1; i <= 5000; i++)
        if (A[i] >= 2)
        {
            for (int j = 1; j <= (i - 1) / 2; j++)
            {
                sum += (long long)A[i] * (long long)(A[i] - 1) / 2 * (long long)A[j] * (long long)A[i - j];  //iѡ2��������1��
                sum %= Mod;
            }
            if (i % 2 == 0)
            {
                sum += (long long)A[i] * (long long)(A[i] - 1) / 2 * (long long)A[i / 2] * (long long)(A[i / 2] - 1) / 2;  // iѡ2����i/2ѡ2��
                sum %= Mod;
            }
            if (A[i] >= 3 && A[0] >= 1)  //iѡ3����0ѡ1��
                sum += (long long)A[0] * (long long)A[i] * (long long)(A[i] - 1) * (long long)(A[i] - 2) / 6;
            sum %= Mod;
        }

    cout << sum;
    return 0;
}
