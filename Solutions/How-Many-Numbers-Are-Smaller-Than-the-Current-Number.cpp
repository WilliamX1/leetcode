class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> copy = nums;
        sort(copy.begin(), copy.end());
        unordered_map<int, int> umap;
        for (int i = 0; i < copy.size(); i++) {
            if (!umap.count(copy[i])) 
                umap[copy[i]] = i;
        };
        for (int& num : nums) {
            num = umap[num];
        };
        return nums;
    }
};