#include <iostream>

using namespace std;

long long int A[3340];
const int Mod = 19301;
int main()
{
    int N; cin >> N;
    A[0] = A[1] = 1;

    for (int i = 2; i <= N; i++)
    {
        A[i] += A[i - 1];
        for (int j = 1; j < i; j++)
        {
            A[i] += (A[j - 1] * A[i - j - 1]);
            A[i] %= Mod;
        }
    }
    cout << A[N];
    return 0;
}
