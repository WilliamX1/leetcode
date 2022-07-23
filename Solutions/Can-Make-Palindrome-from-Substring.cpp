class Solution
{
  public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>> &queries)
    {
        int n = s.size();
        vector<vector<int>> prefix(n, vector<int>(26, 0));
        for (int i = 0; i < n; i++)
            prefix[i][s[i] - 'a'] = (i ? prefix[i - 1][s[i] - 'a'] : 0) + 1;
        for (int i = 1; i < n; i++)
            for (int j = 0; j < 26; j++)
                prefix[i][j] += prefix[i - 1][j];
        vector<bool> ans;
        for (const vector<int> &q : queries)
        {
            int left = q[0], right = q[1], k = q[2];
            int tmp = 0;
            for (int i = 0; i < 26; i++)
            {
                // cout << "left: " << left << " right: " << right << "i: " << i << " prefix[right][i] "
                //      << prefix[right][i] << endl;
                tmp += (prefix[right][i] - (left ? prefix[left - 1][i] : 0)) & 1;
            }
            ans.push_back(tmp / 2 <= k);
        };
        return ans;
    }
};