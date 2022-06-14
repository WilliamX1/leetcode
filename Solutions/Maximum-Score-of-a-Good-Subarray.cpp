class Solution
{
  public:
    int maximumScore(vector<int> &nums, int k)
    {
        int n = nums.size();
        int p = nums[k], l = k, r = k;
        int ans = 0;

        while (p > 0)
        {
            while (l - 1 >= 0 && nums[l - 1] >= p)
                l--;
            while (r + 1 < n && nums[r + 1] >= p)
                r++;
            ans = max(ans, p * (r - l + 1));
            p--;
        };
        return ans;
    }
};