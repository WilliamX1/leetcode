#include <iostream>
#include <memory.h>
using namespace std;

long long int B[1000010];
long long int res[20];
long long int cifang[20];

int main()
{
    int N; cin >> N;
    memset(B, 0, sizeof(B));
    memset(res, 0, sizeof(res));
    memset(cifang, 0, sizeof(cifang));

    cifang[0] = 1;
    for (int i = 1; i < 20; i++) cifang[i] = 2 * cifang[i - 1];

    for (int i = 1; i <= N; i++)
    {
        scanf("%lld", &B[i]);
        long long int tmp = B[i];
        for (int j = 0; j < 20 && tmp > 0; j++)
        {
            res[j] += (tmp & 1);
            //cout << (tmp & 1) << " ";
            tmp /= 2;
        }
        //cout << endl;
    }

    long long int sum = 0;
    for (int i = 0; i < 20; i++)
        sum += cifang[i] * res[i] * (res[i] - 1) / 2;

    cout << sum;
    return 0;
}
