class Solution
{
  public:
    int findPeakElement(vector<int> &nums)
    {
        /* O(N) */
        int ans = 0, len = nums.size();
        while (ans < len - 1 && nums[ans] <= nums[ans + 1])
            ans++;
        return ans;
        /* O(log(N)) */
    }
};