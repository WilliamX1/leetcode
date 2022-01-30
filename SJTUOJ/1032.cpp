#include <iostream>

using namespace std;

int A(int m, int n)
{
    if (m == 0)
        return ++n;
    else if (n == 0)
        return A(m - 1, 1);
    else
        return A(m - 1, A(m, n - 1));
}
int main()
{
    int m, n;cin >> m >> n;
    //if (m == 0)
    //    cout << n + 1;
   // else if (m == 1)
   //     cout << n + 2;
   // else if (m == 2)
    //    cout << n + 3;
   // else if (m == 3)
        cout << A(m,n);
    return 0;
}
