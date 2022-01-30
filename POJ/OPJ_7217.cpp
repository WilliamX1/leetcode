#include <iostream>

using namespace std;

int A[10000];

int main()
{
    int N; cin >> N;
    int i = 0, j = 1;

    while (i <= N)
    {
        A[1] = j * N + 1;
        for (i = 2; i <= N && (A[i - 1] % (N - 1) == 0); i++)
            A[i] = A[i - 1] * N / (N - 1) + 1;
        ++j;
    }
    cout << A[N];
    return 0;
}
