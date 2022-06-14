class Solution
{
  public:
    vector<string> stringMatching(vector<string> &words)
    {
        vector<string> answer;
        for (const string &word : words)
        {
            for (const string &word2 : words)
            {
                if (word != word2 && word2.find(word) != string::npos)
                {
                    answer.push_back(word);
                    break;
                };
            };
        };
        return answer;
    }
};