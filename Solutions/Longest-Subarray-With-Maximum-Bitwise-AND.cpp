class Solution
{
  public:
    int longestSubarray(vector<int> &nums)
    {
        int x = *max_element(nums.begin(), nums.end());
        int ans = 0, tmp = 0;
        for (const int &num : nums)
        {
            tmp = num == x ? tmp + 1 : 0;
            ans = max(ans, tmp);
        };
        return ans;
    }
};