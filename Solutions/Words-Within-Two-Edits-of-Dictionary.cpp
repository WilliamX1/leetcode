class Solution
{
  public:
    int distance(const string &str1, const string &str2)
    {
        if (str1.size() != str2.size())
            return 1e9;
        int dis = 0;
        for (int i = 0; i < str1.size(); i++)
            dis += str1[i] != str2[i];
        // cout << str1 << ' ' << str2 << ' ' << dis << endl;
        return dis;
    };
    vector<string> twoEditWords(vector<string> &queries, vector<string> &dictionary)
    {
        vector<string> ans;
        for (string &q : queries)
        {
            for (string &d : dictionary)
                if (distance(q, d) <= 2)
                {
                    // cout << "here" << endl;
                    ans.push_back(q);
                    break;
                };
        };
        return ans;
    }
};