class Solution
{
  public:
    int minOperations(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        int ans = INT_MAX, n = nums.size();
        vector<int> counts;
        for (int i = 1; i < n; i++)
            if (nums[i] == nums[i - 1])
                counts.push_back(i);

        for (int left = 0; left < n; left++)
        {
            int right = upper_bound(nums.begin(), nums.end(), n - 1 + nums[left]) - nums.begin();
            int same =
                upper_bound(counts.begin(), counts.end(), right) - lower_bound(counts.begin(), counts.end(), left);
            // cout << left << ' ' << right << ' ' << same << endl;
            if (right == n)
                ans = min(ans, left + same);
            else
                ans = min(ans, n - right + left + same);
        };
        return ans;
    }
};