class Solution
{
  public:
    int numIdenticalPairs(vector<int> &nums)
    {
        unordered_map<int, int> count;
        for (const int &num : nums)
            count[num]++;
        int ans = 0;
        for (auto &iter : count)
        {
            int c = iter.second;
            ans += c * (c - 1) / 2;
        };
        return ans;
    }
};