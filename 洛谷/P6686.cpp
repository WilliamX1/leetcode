#include <iostream>
#include <memory.h>
#include <cmath>
using namespace std;

long long int A[200010];
long long int B[200010];
int main()
{
    memset(A, 0, sizeof(A));
    int N; cin >> N;

    int tmp;
    for (int i = 1; i <= N; i++)
    { cin >> tmp; A[tmp]++;}

    B[0] = 0;
    for (int i = 1; i <= 200001; i++)
        B[i] = B[i - 1] + A[i - 1];  //С��B[i]����

    long long int sum = 0;
    long long int Mod = 998244353;

    for (int i = 1; i <= 200000; i++)
    {
        if (A[i] == 2)
            sum += (B[min(2 * i, 200001)] - A[i]);  //С�������߳��ҳ�������i
        else if (A[i] >= 3)
            sum += A[i] * (A[i] - 1) * (A[i] - 2) / 6 + (B[min(2 * i, 200001)] - A[i]) * A[i] * (A[i] - 1) / 2;
            //�ֱ��ڳ���Ϊi��ѡȡ�������ڳ���Ϊi��ѡȡ2����С�������߳��ҳ�������i��ѡȡ1����
        sum %= Mod;
    }
    cout << sum;

    return 0;
}
