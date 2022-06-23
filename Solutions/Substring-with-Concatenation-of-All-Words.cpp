class Solution
{
  public:
    vector<int> findSubstring(string s, vector<string> &words)
    {
        unordered_map<string, int> count_word;
        for (const string &word : words)
            count_word[word]++;
        vector<int> ans;
        int ns = s.size(), nw = words.size(), nword = words[0].size();
        for (int i = 0; i < nword; i++)
        {
            unordered_map<string, int> count_sub;
            int cnt = nw, j = i, jlast = i, cnt_tot = 0;
            string sub, sublast;
            while (cnt-- > 0)
            {
                sub.clear();
                while (j < ns && sub.size() < nword)
                    sub.push_back(s[j++]);
                if (count_word[sub])
                {
                    if (count_sub[sub] < count_word[sub])
                        cnt_tot++;
                    count_sub[sub]++;
                };
            };
            if (cnt_tot == nw)
                ans.push_back(i);

            while (j < ns)
            {
                sub.clear();
                sublast.clear();
                while (j < ns && sub.size() < nword)
                    sub.push_back(s[j++]);
                while (jlast < ns && sublast.size() < nword)
                    sublast.push_back(s[jlast++]);

                if (count_word[sublast])
                {
                    count_sub[sublast]--;
                    if (count_sub[sublast] < count_word[sublast])
                        cnt_tot--;
                };

                if (count_word[sub])
                {
                    if (count_sub[sub] < count_word[sub])
                        cnt_tot++;
                    count_sub[sub]++;
                };
                if (cnt_tot == nw)
                    ans.push_back(jlast);
            };
        };
        return ans;
    }
};