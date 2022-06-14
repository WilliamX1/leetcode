#include <bits/stdc++.h>

using namespace std;

class Solution
{
  public:
    int numSubmatrixSumTarget(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size(), n = matrix[0].size();

        /* 前缀和数组 */
        /* prefix_sum[p][q] - prefix[k][s] = sum(matrix[i][j]) i = k + 1,...,p  j = s + 1,...,q*/
        vector<vector<int>> prefix_matrix(m + 1, vector<int>(n + 1, 0));

        /* 构造每行前缀和数组 */
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
                prefix_matrix[i + 1][j + 1] = prefix_matrix[i + 1][j] + matrix[i][j];
        };
        /* 构造每列前缀和数组 */
        for (int j = 1; j <= n; j++)
            for (int i = 1; i <= m; i++)
                prefix_matrix[i][j] += prefix_matrix[i - 1][j];

        // cout << "*******答案*******" << endl;
        int ans = 0;
        vector<int> cur_line(n + 1, 0);
        for (int i = 1; i <= m; i++)
        {
            for (int k = i; k <= m; k++)
            {
                for (int j = 1; j <= n; j++)
                {
                    cur_line[j] = prefix_matrix[k][j] - prefix_matrix[i - 1][j];
                };
                for (int j = 1; j <= n; j++)
                    for (int s = j; s <= n; s++)
                        if (cur_line[s] - cur_line[j - 1] == target)
                            ans++;
            }
        }
        return ans;
    }
};

int main()
{
    vector<vector<int>> v = {{-1, 1}, {1, -1}};
    Solution S;
    cout << S.numSubmatrixSumTarget(v, 0) << endl;
    return 0;
}