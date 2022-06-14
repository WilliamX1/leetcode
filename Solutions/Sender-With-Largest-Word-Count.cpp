class Solution
{
  public:
    string largestWordCount(vector<string> &messages, vector<string> &senders)
    {
        unordered_map<string, int> counts;
        for (int i = 0; i < messages.size(); i++)
        {
            for (int j = 0; j < messages[i].size(); ++j)
            {
                if (messages[i][j] == ' ')
                    counts[senders[i]]++;
            };
            counts[senders[i]]++;
        };
        string ans = "";
        int cnt = 0;
        for (auto iter : counts)
        {
            if (iter.second > cnt || iter.second == cnt && iter.first > ans)
            {
                cnt = iter.second;
                ans = iter.first;
            };
        };
        return ans;
    }
};