#include <iostream>
#include <algorithm>
using namespace std;
int A[10001];
int B[10001];

int main()
{
    int n; cin >> n;
    int s, a, b, l, r, sum, tmp;
    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        cin >> a;
        for (int j = 1; j <= a; j++)
            cin >> A[j];
        cin >> b;
        for (int j = 1; j <= b; j++)
            cin >> B[j];
        sort(A + 1, A + a + 1);
        sort(B + 1, B + b + 1);

        sum = 0; r = b;
        for (l = 1; l <= a; l++)
        {
            tmp = l;
            for (; l < a && A[l + 1] == A[l]; l++);
            tmp = l - tmp + 1;
            while(r >= 1)
            {
                if (A[l] + B[r] == s)
                    sum += tmp;
                else if (A[l] + B[r] < s)
                    break;
                r--;
            }
        }
        cout << sum << endl;
    }

    return 0;
}
