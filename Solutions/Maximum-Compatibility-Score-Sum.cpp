#include <bits/stdc++.h>

using namespace std;

class Solution
{
  public:
    int ans = 0;
    void dfs(vector<vector<int>> &students, vector<vector<int>> &mentors, int x, const int &m, const int &n,
             vector<bool> m_flag, int tot)
    {
        if (x == m)
        {
            ans = max(ans, tot);
            return;
        };
        for (int j = 0; j < m; j++)
        {
            if (!m_flag[j])
            {
                m_flag[j] = true;

                int tmp = 0;
                for (int i = 0; i < n; i++)
                    tmp += abs(students[x][i] - mentors[j][i]);
                dfs(students, mentors, x + 1, m, n, m_flag, tot + n - tmp);

                m_flag[j] = false;
            };
        };
        return;
    }
    int maxCompatibilitySum(vector<vector<int>> &students, vector<vector<int>> &mentors)
    {
        int m = students.size(), n = students[0].size();
        vector<bool> m_flag(m, 0);
        dfs(students, mentors, 0, m, n, m_flag, 0);
        return ans;
    }
};