class Solution
{
  public:
    bool dfs(const vector<int> &v, const int &n, const int i)
    {
        if (n == 0)
            return true;
        if (i == v.size() || n < 0)
            return false;
        return dfs(v, n - v[i], i + 1) || dfs(v, n, i + 1);
    };
    bool checkPowersOfThree(int n)
    {
        vector<int> v;
        int x = 1;
        while (x <= n)
        {
            v.push_back(x);
            x *= 3;
        };
        return dfs(v, n, 0);
    }
};