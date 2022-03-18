class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> umap;
        int ans = 0;
        for (const int& ele : arr) {
            umap[ele] = max(umap[ele], umap[ele - difference] + 1);
            ans = max(ans, umap[ele]);
        };
        return ans;
    }
};