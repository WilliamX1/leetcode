class Solution
{
  public:
    int similarPairs(vector<string> &words)
    {
        unordered_map<int, int> count;
        for (const string &word : words)
        {
            int tmp = 0;
            for (const char &ch : word)
                tmp |= 1 << (ch - 'a');
            count[tmp]++;
        };
        int ans = 0;
        for (auto &[u, v] : count)
            ans += v * (v - 1) / 2;
        return ans;
    }
};