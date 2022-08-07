class Solution
{
  public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>> &items1, vector<vector<int>> &items2)
    {
        map<int, int> umap;
        for (const vector<int> &v : items1)
            umap[v[0]] += v[1];
        for (const vector<int> &v : items2)
            umap[v[0]] += v[1];
        vector<vector<int>> ans;
        for (auto iter : umap)
            ans.push_back({iter.first, iter.second});
        return ans;
    }
};