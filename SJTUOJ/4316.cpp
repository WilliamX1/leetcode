#include <iostream>

using namespace std;

int A[10010];
int B[10010];

int main()
{
    int N1, N2; cin >> N1 >> N2;

    for (int i = 1; i <= N1; i++)
        cin >> A[i];
    for (int i = 1; i <= N2; i++)
        cin >> B[i];

    int A_xb = 1, B_xb = 1;

    for (int i = 1; i <= N1 + N2 && A_xb <= N1 && B_xb <= N2; i++)
    {
        if (A[A_xb] < B[B_xb])
        {
            cout << A[A_xb] << endl;
            A_xb++;
        }
        else
        {
            cout << B[B_xb] << endl;
            B_xb++;
        }
    }

    for (int i = A_xb; i <= N1; i++)
        cout << A[i] << endl;
    for (int i = B_xb; i <= N2; i++)
        cout << B[i] << endl;
    return 0;
}
