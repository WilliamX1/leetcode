class Solution
{
  public:
    int countHillValley(vector<int> &nums)
    {
        vector<int> nnums;
        nnums.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++)
            if (nums[i] != nnums.back())
                nnums.push_back(nums[i]);
        nums = nnums;
        int n = nums.size(), ans = 0;
        for (int i = 0; i < n; i++)
        {
            int left = i - 1, right = i + 1;
            while (left >= 0 && nums[i] == nums[left])
                left--;
            while (right < n && nums[i] == nums[right])
                right++;

            ans += left >= 0 && right < n &&
                   (nums[left] > nums[i] && nums[right] > nums[i] || nums[left] < nums[i] && nums[right] < nums[i]);
        };
        return ans;
    }
};