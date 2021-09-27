class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int tmp = 0;
        for (auto& num : nums) tmp ^= num;
        int mask = 1;
        while ((tmp & mask) == 0) mask <<= 1;
        int left = 0, right = 0;
        for (auto& num : nums) 
            if ((num & mask) == 0) left ^= num;
            else right ^= num;
        return {left, right};
    }
};