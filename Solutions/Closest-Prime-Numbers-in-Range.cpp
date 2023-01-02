class Solution
{
  public:
    vector<int> findPrime(int n)
    {
        vector<int> flags(n + 1, true), ans;
        for (int64_t i = 2; i <= n; i++)
            if (flags[i])
            {
                ans.push_back(i);
                for (int64_t j = i * i; j <= n; j += i)
                    flags[j] = false;
            };
        return ans;
    }
    vector<int> closestPrimes(int left, int right)
    {
        vector<int> ans = findPrime(right);
        int start_idx = lower_bound(ans.begin(), ans.end(), left) - ans.begin(), size = ans.size();
        if (ans.empty() || start_idx == size - 1)
            return {-1, -1};
        else
        {
            int gap = 0x7fffffff, nums2 = -1;
            for (int i = size - 1; i > start_idx; i--)
            {
                if (ans[i] - ans[i - 1] <= gap)
                {
                    gap = ans[i] - ans[i - 1];
                    nums2 = i;
                };
            };
            return {ans[nums2 - 1], ans[nums2]};
        };
    }
};