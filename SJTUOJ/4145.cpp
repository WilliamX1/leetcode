#include <iostream>

using namespace std;

int A[300010];
long long A_index = -1;

int main()
{
    long long n, x, y; cin >> n >> x >> y;

    char str[300010];
    cin >> str;
    str[n] = '1';

    int tmp = 0;
    for (int i = 0; i <= n; i++)
    {
        if (str[i] == '1')
            if (tmp)
                A[++A_index] = tmp, tmp = 0;
            else continue;
        else
            tmp++;
    }
    //for (int i = 0; i <= A_index; i++) cout << A[i] << " ";

    if (A_index == -1) cout << 0;
    else if (x < y)
        cout << x * A_index + y;
    else cout << y * (A_index + 1);
    return 0;
}
