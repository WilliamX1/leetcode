class Solution
{
  public:
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        int n = nums.size();
        vector<bool> flag(n + 1, false);
        for (int i = 0; i < n; i++)
            flag[nums[i]] = true;
        vector<int> res;
        for (int i = 1; i <= n; i++)
            if (!flag[i])
                res.push_back(i);
        return res;
    }
};