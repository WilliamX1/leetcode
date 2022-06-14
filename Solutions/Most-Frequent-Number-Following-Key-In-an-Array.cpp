class Solution
{
  public:
    int mostFrequent(vector<int> &nums, int key)
    {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size() - 1; i++)
            if (key == nums[i])
                m[nums[i + 1]]++;

        int ans, tot = 0;
        for (auto iter = m.begin(); iter != m.end(); iter++)
            if (iter->second > tot)
            {
                ans = iter->first;
                tot = iter->second;
            };
        return ans;
    }
};