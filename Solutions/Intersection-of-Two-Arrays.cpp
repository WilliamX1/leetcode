class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, bool> umap1, umap2;
        vector<int> ans;
        for (const int& num : nums1) umap1[num] = true;
        for (const int& num : nums2) umap2[num] = true;
        for (const auto ele : umap1)
            if (umap1[ele.first] && umap2[ele.first]) {
                ans.push_back(ele.first);
                umap1[ele.first] = umap2[ele.first] = false;
            };
        for (const auto ele : umap2)
            if (umap1[ele.first] && umap2[ele.first]) {
                ans.push_back(ele.first);
                umap1[ele.first] = umap2[ele.first] = false;
            };
        return ans;
    }
};