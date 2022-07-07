class Solution
{
  public:
    bool isPalindrom(const string &a)
    {
        int n = a.size();
        for (int i = 0; i < n; i++)
            if (a[i] != a[n - i - 1])
                return false;
        return !!n;
    };
    int dfs(const string &s, const int &n, const int &i, string &a, string &b)
    {
        if (i == n)
        {
            if (isPalindrom(a) && isPalindrom(b))
                return a.size() * b.size();
            else
                return 0;
        }
        else
        {
            int ans = 0;
            a.push_back(s[i]);
            ans = max(ans, dfs(s, n, i + 1, a, b));
            a.pop_back();

            b.push_back(s[i]);
            ans = max(ans, dfs(s, n, i + 1, a, b));
            b.pop_back();

            ans = max(ans, dfs(s, n, i + 1, a, b));
            return ans;
        };
    }
    int maxProduct(string s)
    {
        string a, b;
        return dfs(s, s.size(), 0, a, b);
    }
};