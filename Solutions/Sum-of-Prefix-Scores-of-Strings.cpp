class Solution
{
  public:
    vector<int> sumPrefixScores(vector<string> &words)
    {
        struct node
        {
            node *sons[26]{};
            int val;
            node(int v = 0) : val(v){};
        };

        node *root = new node();
        for (const string &word : words)
        {
            node *p = root;
            for (const char &ch : word)
            {
                if (p->sons[ch - 'a'] == nullptr)
                    p = p->sons[ch - 'a'] = new node(1);
                else
                {
                    p = p->sons[ch - 'a'];
                    p->val++;
                };
            };
        };
        vector<int> ans;
        for (const string &word : words)
        {
            node *p = root;
            int cnt = 0;
            for (const char &ch : word)
            {
                p = p->sons[ch - 'a'];
                cnt += p->val;
            };
            ans.push_back(cnt);
        };
        return ans;
    }
};