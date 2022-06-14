class Solution
{
  public:
    int numSplits(string s)
    {
        int n = s.size();
        set<int> se;
        vector<int> forward(n, 0);
        vector<int> backward(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            se.insert(s[i]);
            forward[i] = se.size();
        };
        se.clear();
        for (int i = n - 1; i >= 0; i--)
        {
            se.insert(s[i]);
            backward[i] = se.size();
        };
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += forward[i] == backward[i + 1];
        };
        return ans;
    }
};