#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int m, n, k; cin >> m >> n >> k;

    vector<vector<int>> nums(m, vector<int>(n / m + 1, 0));

    int idx = 1, x, y;
    for (int j = 0; idx <= n; j++)
        for (int i = 0; i < m && idx <= n; i++) {
            nums[i][j] = idx;
            if (idx == k) {
                x = i;
                y = j;
            };
            idx++;
        };
    int ans = (y > 0) + (x > 0);

    int cnt = 0;
    for (int i = x; i < m; i++)
        for (int j = y; j < n / m + 1; j++) {
            if (nums[i][j])
                cnt++;
        };
    // cout << cnt << endl;
    if (cnt == 1) ans += 0;
    else if (cnt <= m || m == 1) ans += 1;
    else ans += 2;

    if (x == 0 || x == m - 1)
        ans = min(ans, 3);
    cout << ans << endl;
    return 0;
}