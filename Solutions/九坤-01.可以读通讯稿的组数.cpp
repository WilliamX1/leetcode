class Solution
{
  public:
    int getMirror(int num)
    {
        int ans = 0;
        while (num)
        {
            ans = ans * 10 + (num % 10);
            num /= 10;
        };
        return ans;
    };
    int numberOfPairs(vector<int> &nums)
    {
        unordered_map<int, long long> count;
        for (const int &num : nums)
            count[num - getMirror(num)]++;
        long long ans = 0, mod = 1e9 + 7;
        for (auto &iter : count)
            ans = (ans + iter.second * (iter.second - 1) / 2) % mod;
        return ans;
    }
};