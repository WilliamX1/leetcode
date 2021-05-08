class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int ans = 0x7fffffff;
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] == target && abs(i - start) < ans)
                ans = abs(i - start);
        return ans;
    }
};