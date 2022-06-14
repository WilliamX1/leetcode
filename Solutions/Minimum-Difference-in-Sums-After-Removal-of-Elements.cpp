#include <queue>
#include <vector>

using namespace std;

class Solution
{
  public:
    long long minimumDifference(vector<int> &nums)
    {
        priority_queue<int64_t, vector<int64_t>, less<int64_t>> pre;     /* 大顶堆 */
        priority_queue<int64_t, vector<int64_t>, greater<int64_t>> post; /* 小顶堆 */
        int64_t n = nums.size() / 3;
        int64_t pre_sum = 0, post_sum = 0;
        for (int64_t i = 0; i < n; i++)
        {
            pre.push(nums[i]);
            post.push(nums[3 * n - i - 1]);
            pre_sum += nums[i];
            post_sum += nums[3 * n - i - 1];
        };

        vector<int64_t> pre_v(3 * n, 1000000000), post_v(3 * n, -1000000000);

        pre_v[n - 1] = pre_sum;
        for (int64_t i = n; i < 2 * n; i++)
        {
            if (nums[i] < pre.top())
            {
                int64_t t = pre.top();
                pre.pop();
                pre.push(nums[i]);
                pre_sum += nums[i] - t;
            };
            pre_v[i] = pre_sum;
        };

        post_v[2 * n] = post_sum;
        for (int64_t i = 2 * n - 1; i >= n; i--)
        {
            if (nums[i] > post.top())
            {
                int64_t t = post.top();
                post.pop();
                post.push(nums[i]);
                post_sum += nums[i] - t;
            };
            post_v[i] = post_sum;
        };

        int64_t ans = 0x7ffffffffffffff;
        for (int64_t i = n; i <= 2 * n; i++)
        {
            ans = min(ans, pre_v[i - 1] - post_v[i]);
        };
        return ans;
    }
};