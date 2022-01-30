#include <iostream>
#include <algorithm>
using namespace std;
int A[1200];
int B[1200];

int main()
{
    int N; cin >> N;
    for (int i = 1; i <= N; i++)
        {
            cin >> A[i];
            B[i] = 1;
        }
    for (int i = 1; i <= N; i++)
        for (int j = i - 1; j >= 0; j--)
            if (A[j] < A[i])
                B[i] = max(B[i], B[j] + 1);
    cout << *max_element(B + 1, B + N + 1);
    return 0;
}
