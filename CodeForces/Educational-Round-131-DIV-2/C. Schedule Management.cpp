#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int64_t t;
    cin >> t;

    while (t--)
    {
        int64_t n, m;
        cin >> n >> m;

        vector<int64_t> nums(n + 1, 0);
        int64_t ai;
        for (int64_t i = 1; i <= m; i++)
        {
            cin >> ai;
            nums[ai]++;
        };

        int64_t left = 0, right = 1e8;
        while (left <= right)
        {
            int64_t mid = (left + right) >> 1;
            int64_t more = 0;
            for (int64_t i = 1; i <= n; i++)
            {
                if (nums[i] <= mid)
                    more += (mid - nums[i]) >> 1;
                else
                    more -= (nums[i] - mid);
            };
            if (more >= 0)
                right = mid - 1;
            else
                left = mid + 1;
        };
        cout << left << endl;
    };
    return 0;
}