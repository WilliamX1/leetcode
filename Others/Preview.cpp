#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

struct node
{
    int64_t low;
    int64_t high;
    int64_t a;
    int64_t b;
    node(){};
    node(int64_t l, int64_t h, int64_t a, int64_t b) : low(l), high(h), a(a), b(b){};
};

int main()
{
    int64_t n;
    cin >> n;

    vector<int64_t> a(n + 1), b(n + 1);
    for (int64_t i = 1; i <= n; i++)
        cin >> a[i];
    for (int64_t i = 1; i <= n; i++)
        cin >> b[i];

    vector<node> nums;
    for (int64_t i = 1; i <= n; i++)
        nums.emplace_back(i - a[i] + 1, i + a[i] - 1, a[i], b[i]);

    sort(nums.begin(), nums.end(), [](const node &a, const node &b) { return a.high < b.high; });

    vector<int64_t> dp(2 * n + 7, 0);

    int64_t ptr = 0, nsize = nums.size();
    for (int64_t i = 1; i < 2 * n + 7; i++)
    {
        // cout << ptr << ' ' << i << ' ' << nums[ptr].low << ' ' << nums[ptr].high << ' ' << nums[ptr].a << ' '
        //      << nums[ptr].b << endl;
        dp[i] = dp[i - 1];
        while (ptr < nsize && nums[ptr].high == i)
        {
            dp[i] = max(dp[i], dp[max(0L, nums[ptr].low)] + nums[ptr].a * nums[ptr].b);
            ptr++;
        }
        // cout << "i: " << i << " dp[i]: " << dp[i] << endl;
    };
    cout << dp.back() << endl;
    return 0;
}