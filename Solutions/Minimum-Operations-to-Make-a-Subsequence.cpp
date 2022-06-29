class Solution
{
  public:
    int minOperations(vector<int> &target, vector<int> &arr)
    {
        unordered_map<int, int> index;
        for (int i = 0; i < target.size(); i++)
            index[target[i]] = i;
        vector<int> v;
        for (const int &a : arr)
            if (index.count(a))
            {
                v.push_back(index[a]);
            };

        int n = v.size(), ans = 0;
        vector<int> dp(n + 1, 0x7fffffff);
        dp[0] = -1;
        for (const int &a : v)
        {
            int it = lower_bound(dp.begin(), dp.end(), a) - dp.begin();
            --it;

            cout << it << ' ';
            dp[it + 1] = min(dp[it + 1], a);
            ans = max(ans, it + 1);
        };
        return target.size() - ans;
    }
};