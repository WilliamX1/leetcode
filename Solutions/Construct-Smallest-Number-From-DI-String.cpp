class Solution
{
  public:
    string ans;

    void dfs(const string &pattern, string &cur, int i, int n, vector<bool> &havebeen)
    {
        // cout << i << ' ' << cur << endl;
        if (!ans.empty())
            return;
        else if (i == n + 1)
        {
            ans = cur;
            return;
        }
        else if (i == 0)
        {
            for (int j = 1; j <= 9; j++)
            {
                havebeen[j] = true;
                cur.push_back(j + '0');
                dfs(pattern, cur, i + 1, n, havebeen);
                cur.pop_back();
                havebeen[j] = false;
            };
        }
        else
        {
            if (pattern[i - 1] == 'I')
            {
                for (int j = cur.back() - '0' + 1; j <= 9; j++)
                    if (!havebeen[j])
                    {
                        havebeen[j] = true;
                        cur.push_back(j + '0');
                        dfs(pattern, cur, i + 1, n, havebeen);
                        cur.pop_back();
                        havebeen[j] = false;
                    };
            }
            else
            {
                for (int j = 1; j <= cur.back() - '0' - 1; j++)
                    if (!havebeen[j])
                    {
                        havebeen[j] = true;
                        cur.push_back(j + '0');
                        dfs(pattern, cur, i + 1, n, havebeen);
                        cur.pop_back();
                        havebeen[j] = false;
                    }
            }
        }
    };
    string smallestNumber(string pattern)
    {
        int n = pattern.size();
        string cur;
        vector<bool> havebeen(9 + 1, false);

        dfs(pattern, cur, 0, n, havebeen);
        return ans;
    }
};