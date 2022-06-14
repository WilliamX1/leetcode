class Solution
{
  public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_map<string, bool> appear;
        for (const string &word : wordList)
            appear[word] = true;
        unordered_map<string, vector<string>> edges;
        wordList.push_back(beginWord);
        for (const string &word : wordList)
        {
            int len = word.size();
            for (int i = 0; i < len; i++)
            {
                for (int j = 'a'; j <= 'z'; j++)
                {
                    if (word[i] != j)
                    {
                        string copy_word = word;
                        copy_word[i] = j;
                        if (appear[copy_word])
                        {
                            edges[word].push_back(copy_word);
                        };
                    };
                };
            };
        };

        unordered_map<string, bool> have_been;
        int level = 1;
        vector<string> cur;
        cur.push_back(beginWord);
        have_been[beginWord] = true;

        while (!cur.empty())
        {
            vector<string> next;
            for (const string &str : cur)
            {
                if (str == endWord)
                    return level;
                vector<string> ed = edges[str];
                for (const string &s : ed)
                {
                    if (!have_been[s])
                    {
                        have_been[s] = true;
                        next.push_back(s);
                    };
                };
            };
            cur = next;
            level++;
        };
        return 0;
    }
};