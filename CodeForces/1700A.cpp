#include <iostream>

using namespace std;

int main()
{
    int64_t t, n, m;
    cin >> t;
    for (int _ = 0; _ < t; _++)
    {
        cin >> n >> m;
        int64_t corner1 = m, corner2 = n * m - m + 1;
        int64_t ans1 = (corner1 + 1) * m / 2 + (corner1 + n * m) * n / 2 - corner1;
        int64_t ans2 = (corner2 + 1) * n / 2 + (corner2 + n * m) * m / 2 - corner2;
        cout << min(ans1, ans2) << endl;
    };
    return 0;
}