class Solution
{
  public:
    long long maximumSubarraySum(vector<int> &nums, int k)
    {
        long long ans = 0, n = nums.size(), tot = 0;

        unordered_map<int, int> count;
        int no = 0;
        for (int i = 0; i < k; i++)
        {
            if (count[nums[i]] == 1)
                no++;
            count[nums[i]]++;
            tot += (long long)nums[i];
        };

        if (!no)
            ans = tot;
        for (int i = k; i < n; i++)
        {
            if (count[nums[i]] == 1)
                no++;
            count[nums[i]]++;
            tot += (long long)nums[i];

            count[nums[i - k]]--;
            if (count[nums[i - k]] == 1)
                no--;
            tot -= (long long)nums[i - k];

            // cout << i << ' ' << no << endl;

            if (!no)
                ans = max(ans, tot);
        };
        return ans;
    }
};