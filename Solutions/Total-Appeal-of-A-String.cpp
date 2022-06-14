class Solution
{
  public:
    long long appealSum(string s)
    {
        long long n = s.size(), ans = 0;
        vector<long long> indexs(26, -1);
        for (long long i = 0; i < n; i++)
        {
            long long l = indexs[s[i] - 'a'];
            ans += (i - l) * (n - i);
            indexs[s[i] - 'a'] = i;
        };
        return ans;
    }
};