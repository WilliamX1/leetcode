class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, string> umap;
        for (const vector<string> path : paths) {
            const string& from = path.front(), end = path.back();
            umap[from] = end;
        };
        string ans = paths.front().front();
        while (umap.find(ans) != umap.end()) {
            ans = umap[ans];
        };
        return ans;
    }
};