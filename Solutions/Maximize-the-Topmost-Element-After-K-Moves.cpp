class Solution
{
  public:
    int maximumTop(vector<int> &nums, int k)
    {
        if (k == 0)
            return nums[0];
        else if (k == 1)
            return nums.size() > 1 ? nums[1] : -1;
        else
        {
            int ans = (nums.size() == 1) && k % 2 == 1 ? -1 : nums[0];
            for (int i = 1; i < nums.size(); i++)
            {
                if (nums[i] > ans && (k == i || k > i + 1))
                    ans = nums[i];
            };
            return ans;
        };
    }
};