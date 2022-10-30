class Solution
{
  public:
    vector<vector<string>> mostPopularCreator(vector<string> &creators, vector<string> &ids, vector<int> &views)
    {
        struct node
        {
            string id;
            int view;
            node(){};
            node(string id, int view) : id(id), view(view){};
        };

        unordered_map<string, node> umap;
        unordered_map<string, int64_t> count;
        int64_t n = creators.size(), M = 0;
        for (int i = 0; i < n; i++)
        {
            string creator = creators[i], id = ids[i];
            int view = views[i];

            count[creator] += view;

            M = max(M, count[creator]);

            if (!umap.count(creator) || umap[creator].view < view ||
                umap[creator].view == view && umap[creator].id > id)
                umap[creator] = node(id, view);
        };

        vector<vector<string>> ans;

        for (const string &creator : creators)
            if (count[creator] == M)
            {
                ans.push_back({creator, umap[creator].id});
                count[creator] = -1;
            };

        return ans;
    }
};