class Solution
{
  public:
    int countKDifference(vector<int> &nums, int k)
    {
        unordered_map<int, int> m;
        int ans = 0;
        for (const int &num : nums)
        {
            ans += m[num + k] + m[num - k];
            m[num]++;
        };
        return ans;
    }
};