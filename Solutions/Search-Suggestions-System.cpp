class Solution
{
  public:
    bool compare(const string &str, const string &prefix)
    {
        int nstr = str.size(), npre = prefix.size();
        if (npre > nstr)
            return false;
        for (int i = 0; i < npre; i++)
            if (prefix[i] != str[i])
                return false;
        return true;
    }
    vector<vector<string>> suggestedProducts(vector<string> &products, string searchWord)
    {
        sort(products.begin(), products.end());
        int n = products.size(), m = searchWord.size(), index = 0;
        vector<vector<string>> ans(m);

        string s;
        for (int i = 0; i < searchWord.size(); i++)
        {
            s += searchWord[i];

            while (index < n && !compare(products[index], s))
                index++;

            if (index < n && compare(products[index], s))
            {
                ans[i].push_back(products[index]);
                if (index + 1 < n && compare(products[index + 1], s))
                {
                    ans[i].push_back(products[index + 1]);
                    if (index + 2 < n && compare(products[index + 2], s))
                    {
                        ans[i].push_back(products[index + 2]);
                    };
                };
            };
        };
        return ans;
    }
};