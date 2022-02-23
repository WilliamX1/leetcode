class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> m;
        for (const auto& num : nums) {
            if (m[num]) return true;
            else m[num]++;
        };
        return false;
    }
};