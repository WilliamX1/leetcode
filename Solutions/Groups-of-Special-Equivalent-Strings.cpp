class Solution
{
  public:
    int numSpecialEquivGroups(vector<string> &words)
    {
        set<string> s;
        for (const string &word : words)
        {
            string odd, even;
            for (int i = 0; i < word.size(); i++)
            {
                if (i & 1)
                    odd.push_back(word[i]);
                else
                    even.push_back(word[i]);
            };
            sort(odd.begin(), odd.end());
            sort(even.begin(), even.end());
            s.insert(odd + even);
        };
        return s.size();
    }
};