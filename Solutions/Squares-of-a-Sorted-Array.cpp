class Solution
{
  public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        sort(nums.begin(), nums.end(), [](const int &a, const int &b) { return abs(a) < abs(b); });
        for (int &num : nums)
            num *= num;
        return nums;
    }
};