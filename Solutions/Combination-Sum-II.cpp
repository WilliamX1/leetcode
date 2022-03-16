class Solution {
public:
    vector<vector<int>> ans;
    void _combinationSum2(unordered_map<int, int>& umap, unordered_map<int, int>::iterator iter, int target, vector<int> v) {
        if (iter == umap.end() || target <= 0) {
            if (target == 0) ans.push_back(v);
            return;
        } else {
            int val = iter->first, cnt = iter->second;
            _combinationSum2(umap, ++iter, target, v);
            while (cnt-- > 0) {
                v.push_back(val);
                target -= val;
                _combinationSum2(umap, iter, target, v);
            };
        }
    };
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        unordered_map<int, int> umap;
        for (const int& can : candidates)
            umap[can]++;
        _combinationSum2(umap, umap.begin(), target, vector<int>());
        return ans;
    }
};