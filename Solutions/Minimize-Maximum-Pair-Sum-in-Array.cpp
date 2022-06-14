class Solution
{
  public:
    int minPairSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int ans = 0, len = nums.size(), n = len >> 1;
        for (int i = 0; i < n; i++)
            ans = max(ans, nums[i] + nums[len - i - 1]);
        return ans;
    }
};