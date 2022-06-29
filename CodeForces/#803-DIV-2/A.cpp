#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        int n, tt = 0;
        cin >> n;
        vector<int> v(n);
        for (int j = 0; j < n; j++)
        {
            cin >> v[j];
            tt ^= v[j];
        };
        for (int j = 0; j < n; j++)
        {
            if (tt ^ v[j] == v[j])
            {
                cout << v[j] << endl;
                break;
            };
        };
    };
    return 0;
}