class Solution
{
  public:
    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        unordered_map<string, bool> words;
        for (const string &word : wordDict)
            words[word] = true;
        int n = s.size();
        vector<vector<vector<int>>> dp(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j >= 0; j--)
            {
                if (words[s.substr(j, i - j + 1)])
                {
                    if (j == 0)
                    {
                        dp[i].push_back(vector<int>(1, i));
                    }
                    else
                    {
                        vector<vector<int>> ins = dp[j - 1];
                        for (int k = 0; k < ins.size(); k++)
                        {
                            ins[k].push_back(i);
                            dp[i].push_back(ins[k]);
                        };
                    };
                };
            };
        };

        vector<string> ans;
        for (vector<int> &v : dp[n - 1])
        {
            int idx = 0;
            string str;
            for (int i = 0; i < n; i++)
            {
                str += s[i];
                if (idx < v.size() && v[idx] == i && i < n - 1)
                {
                    str += ' ';
                    idx++;
                };
            };
            ans.push_back(str);
        };
        return ans;
    }
};