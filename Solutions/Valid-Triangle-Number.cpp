class Solution
{
  public:
    int triangleNumber(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int len = nums.size(), tmp = 0;
        for (int i = 0; i < len; i++)
            nums[i] *= nums[i];

        int ans = 0;
        for (int i = 0; i < len; i++)
            for (int j = i + 1; j < len; j++)
            {
                tmp = lower_bound(nums.begin() + j + 1, nums.end(), nums[i] + nums[j]) - nums.begin();
                ans += tmp >= len ? 0 : tmp - j;
            };
        return ans;
    }
};