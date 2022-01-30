#include <iostream>

using namespace std;

int A[100010];

int main()
{
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> A[i];
    int L, R;
    for (int i = 1; i <= q; i++)
    {
        cin >> L >> R;
        int m = 1e9;
        for (int j = L; j <= R; j++)
            if (A[j] < m) m = A[j];
        cout << m - 1 << endl;
    }
    return 0;
}
