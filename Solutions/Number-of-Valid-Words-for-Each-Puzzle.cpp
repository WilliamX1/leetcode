class Solution
{
  public:
    vector<int> findNumOfValidWords(vector<string> &words, vector<string> &puzzles)
    {
        vector<int> count(1 << 26, 0);
        for (const string &word : words)
        {
            int num = 0;
            for (const char &ch : word)
                num |= 1 << (ch - 'a');
            count[num]++;
        };
        vector<int> ans(puzzles.size(), 0);
        for (int i = 0; i < puzzles.size(); i++)
        {
            const string &puzzle = puzzles[i];
            for (int j = 0; j < (1 << (puzzle.size() - 1)); j++)
            {
                int jj = (j << 1) + 1;
                int num = 0;
                for (int k = 0; k < 7; k++)
                    if (jj & (1 << k))
                        num |= 1 << (puzzle[k] - 'a');
                ans[i] += count[num];
            };
        };
        return ans;
    }
};