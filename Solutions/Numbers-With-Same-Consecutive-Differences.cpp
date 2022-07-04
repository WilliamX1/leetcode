class Solution
{
  public:
    void dfs(string &cur, const int &k, const int &n, vector<int> &ans)
    {
        if (!n)
        {
            ans.push_back(stol(cur));
            return;
        }
        else
        {
            int last_num = cur.back() - '0';
            if (k == 0)
            {
                cur.push_back(last_num + '0');
                dfs(cur, k, n - 1, ans);
                cur.pop_back();
            }
            else
            {
                if (0 <= last_num - k && last_num - k < 10)
                {
                    cur.push_back(last_num - k + '0');
                    dfs(cur, k, n - 1, ans);
                    cur.pop_back();
                };
                if (0 <= last_num + k && last_num + k < 10)
                {
                    cur.push_back(last_num + k + '0');
                    dfs(cur, k, n - 1, ans);
                    cur.pop_back();
                };
            };
        };
    };
    vector<int> numsSameConsecDiff(int n, int k)
    {
        vector<int> ans;

        for (int i = 1; i <= 9; i++)
        {
            string num = to_string(i);
            dfs(num, k, n - 1, ans);
        };
        return ans;
    }
};