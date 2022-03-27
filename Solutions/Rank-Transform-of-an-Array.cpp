class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> copy = arr;
        sort(arr.begin(), arr.end(), less<int>());
        unordered_map<int, int> umap;
        int idx = 1;
        for (int i = 0; i < arr.size(); i++) {
            if (umap.count(arr[i]) == 0) {
                umap[arr[i]] = idx++;
            };
        };
        for (int& ele : copy) {
            ele = umap[ele];
        };
        return copy;
    }
};