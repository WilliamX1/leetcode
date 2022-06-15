class Solution
{
  public:
    vector<string> removeSubfolders(vector<string> &folder)
    {
        sort(folder.begin(), folder.end(), [](const string &a, const string &b) { return a.size() < b.size(); });
        unordered_map<string, bool> appear;
        vector<string> ans;
        for (const string &f : folder)
        {
            string tmp;
            for (int i = 0; i < f.size(); i++)
            {
                if (f[i] == '/' && appear[tmp])
                    break;
                tmp.push_back(f[i]);
            };
            if (tmp == f)
                ans.push_back(f);
            appear[f] = true;
        };
        return ans;
    }
};