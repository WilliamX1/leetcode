class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int ans = 1e9 + 7;
        for (const int& num : nums)
            if (abs(num) < abs(ans) || abs(num) == abs(ans) && num > ans) ans = num;
        return ans;
    }
};