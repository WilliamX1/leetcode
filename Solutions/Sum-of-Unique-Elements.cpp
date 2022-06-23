class Solution
{
  public:
    int sumOfUnique(vector<int> &nums)
    {
        unordered_map<int, int> cnt;
        for (const int &num : nums)
            cnt[num]++;
        int ans = 0;
        for (auto &[u, v] : cnt)
            if (v == 1)
                ans += u;
        return ans;
    }
};