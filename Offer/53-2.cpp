class Solution
{
  public:
    int missingNumber(vector<int> &nums)
    {
        int len = nums.size();
        return len * (len + 1) / 2 - accumulate(nums.begin(), nums.end(), 0);
    }
};