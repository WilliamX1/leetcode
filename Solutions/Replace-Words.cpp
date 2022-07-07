class Solution
{
  public:
    string replaceWords(vector<string> &dictionary, string sentence)
    {
        unordered_map<string, bool> umap;
        for (const string &s : dictionary)
            umap[s] = true;

        int n = sentence.size();
        string ans;

        string str;
        for (int i = 0; i < n; i++)
        {
            if (sentence[i] == ' ')
            {
                string tmp;
                for (const char &ch : str)
                {
                    tmp.push_back(ch);
                    if (umap[tmp])
                        break;
                };
                ans.append(tmp);
                ans.push_back(' ');
                str.clear();
            }
            else
                str.push_back(sentence[i]);
        };

        string tmp;
        for (const char &ch : str)
        {
            tmp.push_back(ch);
            if (umap[tmp])
                break;
        };
        ans.append(tmp);

        return ans;
    }
};