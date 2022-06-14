class Solution
{
  public:
    int subarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> m;
        m.insert(make_pair(0, 1));
        int len = nums.size(), count = 0, ans = 0;
        for (int i = 0; i < len; i++)
        {
            count += nums[i];
            auto iter = m.find(count - k);
            if (iter != m.end())
                ans += iter->second;

            iter = m.find(count);
            if (iter != m.end())
                iter->second++;
            else
                m.insert(make_pair(count, 1));
        };
        return ans;
    }
};