#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t, n;
    cin >> t;

    while (t-- > 0)
    {
        cin >> n;
        vector<int64_t> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];

        int64_t prefix = 0, suffix = 0, ans = 0;
        for (int i = 0; i < n - 1; i++)
            if (v[i + 1] >= v[i])
                suffix += v[i + 1] - v[i];
            else
                prefix += v[i] - v[i + 1];
        ans = prefix + suffix + abs(v[0] - prefix);
        cout << ans << endl;
    };
    return 0;
}