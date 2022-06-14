class Solution
{
  public:
    void dfs(const vector<vector<int>> &statements, const int n, vector<bool> previous, int k, int &cur_max)
    {
        if (k == n)
        {
            for (int i = 0; i < n; i++)
            {
                if (previous[i] == true)
                {
                    for (int j = 0; j < n; j++)
                    {
                        if (statements[i][j] == 2 || statements[i][j] == previous[j])
                            continue;
                        else
                            return;
                    }
                }
            };
            cur_max = max(cur_max, accumulate(previous.begin(), previous.end(), 0));
            return;
        }
        else
        {
            /* 生成下一位 */
            int cnt = accumulate(previous.begin(), previous.end(), 0) + n - k;
            if (cnt <= cur_max)
                return;

            if (cnt - 1 > cur_max)
            {
                vector<bool> false_previous = previous;
                false_previous.push_back(false);
                dfs(statements, n, false_previous, k + 1, cur_max);
            };

            for (int i = 0; i < k; i++)
            {
                if (statements[k][i] == 2 || statements[k][i] == previous[i])
                    continue;
                else
                    return;
            };
            vector<bool> true_previous = previous;
            true_previous.push_back(true);
            dfs(statements, n, true_previous, k + 1, cur_max);

            return;
        };
    };
    int maximumGood(vector<vector<int>> &statements)
    {
        vector<bool> previous;
        int n = statements.size();
        int res = 0;
        dfs(statements, n, previous, 0, res);
        return res;
    };
};