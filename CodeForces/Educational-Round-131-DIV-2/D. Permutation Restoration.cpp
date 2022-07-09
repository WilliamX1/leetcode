#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int main()
{
    int64_t t;
    cin >> t;

    while (t--)
    {
        int64_t n;
        cin >> n;

        vector<int64_t> nums(n + 1);
        for (int64_t i = 1; i <= n; i++)
            cin >> nums[i];

        vector<int64_t> ans(n + 1);

        vector<vector<int64_t>> v;
        for (int64_t i = 1; i <= n; i++)
        {
            int64_t lower, upper;

            if (nums[i] == 0)
            {
                lower = i + 1;
                upper = n;
            }
            else
            {
                lower = i / (nums[i] + 1) + 1;
                upper = i / nums[i];

                int l;
                for (l = min(upper, lower + 1); l >= 1; l--)
                    if (l / lower == nums[i])
                        lower = l;
            };
            v.push_back({lower, upper - lower + 1, i});

            // cout << "i: " << i << " lower: " << lower << " upper: " << upper << endl;
        };

        sort(v.begin(), v.end(), [](const vector<int64_t> &a, const vector<int64_t> &b) {
            return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
        });

        for (int64_t i = 1; i <= n; i++)
            ans[v[i - 1][2]] = i;

        for (int64_t i = 1; i <= n; i++)
            cout << ans[i] << ' ';

        cout << endl;
    };
    return 0;
}