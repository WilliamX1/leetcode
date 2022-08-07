class Solution
{
  public:
    bool validPartition(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 2)
            return nums[0] == nums[1];
        else
        {
            vector<bool> ans(n, false);
            ans[1] = nums[0] == nums[1];
            ans[2] = nums[0] == nums[1] && nums[1] == nums[2] || nums[0] + 1 == nums[1] && nums[1] + 1 == nums[2];

            for (int i = 3; i < n; i++)
            {
                ans[i] = ans[i - 2] && nums[i] == nums[i - 1] ||
                         ans[i - 3] && (nums[i] == nums[i - 1] && nums[i] == nums[i - 2] ||
                                        nums[i] == nums[i - 1] + 1 && nums[i - 1] == nums[i - 2] + 1);
            };
            return ans.back();
        };
    }
};