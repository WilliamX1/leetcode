class Solution
{
  public:
    int maxScore(string s)
    {
        int n = s.size();
        vector<int> zeros(n), ones(n);
        zeros[0] = s[0] == '0';
        ones[0] = s[0] == '1';
        for (int i = 1; i < n; i++)
        {
            zeros[i] = zeros[i - 1] + (s[i] == '0');
            ones[i] = ones[i - 1] + (s[i] == '1');
        };
        int ans = 0;
        for (int i = 0; i < n - 1; i++)
        {
            ans = max(ans, zeros[i] + ones[n - 1] - ones[i]);
        };
        return ans;
    }
};