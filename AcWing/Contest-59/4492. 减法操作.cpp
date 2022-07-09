#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int64_t n;
    cin >> n;

    int64_t d = n;
    for (int64_t i = 2; i <= sqrt(n + 1) + 1; i++)
        if ((n % i) == 0)
        {
            d = i;
            break;
        };

    if (d == n)
        cout << 1 << endl;
    else
    {
        int64_t another = n / d;
        if (d == 2)
            cout << another << endl;
        else
            cout << 1 + d * (another - 1) / 2 << endl;
    }
    return 0;
}