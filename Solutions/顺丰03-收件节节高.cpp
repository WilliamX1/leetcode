class Solution
{
  public:
    int findMaxCI(vector<int> &nums)
    {
        if (nums.size() <= 1)
            return nums.size();
        int ans = 0, cnt = 1;
        for (int i = 1; i < nums.size(); i++)
            if (nums[i] > nums[i - 1])
                cnt++;
            else
            {
                ans = max(ans, cnt);
                cnt = 1;
            };
        ans = max(ans, cnt);
        return ans;
    }
};