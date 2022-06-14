class Solution
{
  public:
    vector<string> findAndReplacePattern(vector<string> &words, string pattern)
    {
        for (auto iter = words.begin(); iter != words.end();)
        {
            string str = *iter;
            int n = str.size(), flag = true;
            unordered_map<char, char> str2pattern, pattern2str;
            for (int i = 0; i < n; ++i)
            {
                if (str2pattern.count(str[i]) && str2pattern[str[i]] != pattern[i] ||
                    pattern2str.count(pattern[i]) && pattern2str[pattern[i]] != str[i])
                {
                    flag = false;
                    break;
                }
                else
                {
                    str2pattern[str[i]] = pattern[i];
                    pattern2str[pattern[i]] = str[i];
                };
            };
            if (flag)
                iter++;
            else
                iter = words.erase(iter);
        };
        return words;
    }
};