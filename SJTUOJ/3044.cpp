#include <iostream>

using namespace std;

long long int A[1010];
long long int Mod = 1000000000 + 7;
int main()
{
    int N; cin >> N;

    A[0] = 1;
    A[1] = 1;

    for (int i = 2; i <= N; i++)
    {
        int x = i;
        while(x >= 0)
        {
            if (x % 2 == 0)
            {
                A[i] += A[x / 2];
                x -= 2;
            }
            else
            {
                A[i] += A[(x - 1) / 2];
                x -= 2;
            }
        }
        A[i] %= Mod;
    }
    cout << A[N];
    return 0;
}
