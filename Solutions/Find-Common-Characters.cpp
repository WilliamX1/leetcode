class Solution
{
  public:
    vector<string> commonChars(vector<string> &words)
    {
        vector<vector<int>> v(words.size(), vector<int>(26, 0));
        for (int i = 0; i < words.size(); i++)
            for (const char &ch : words[i])
                v[i][ch - 'a']++;
        vector<string> ans;
        for (char ch = 'a'; ch <= 'z'; ch++)
        {
            int m = INT32_MAX;
            for (int i = 0; i < words.size(); i++)
                m = min(m, v[i][ch - 'a']);
            while (m--)
                ans.emplace_back(1, ch);
        };

        return ans;
    }
};