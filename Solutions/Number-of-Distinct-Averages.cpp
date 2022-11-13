class Solution
{
  public:
    int distinctAverages(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        set<int> s;

        int n = nums.size();
        for (int i = 0; i < n; i++)
            s.insert(nums[i] + nums[n - i - 1]);
        return s.size();
    }
};