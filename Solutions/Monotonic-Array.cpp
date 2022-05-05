class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        if (nums.size() <= 1) return true;
        int index = 1, n = nums.size();
        while (index < n && nums[index] == nums[index - 1]) index++;
        if (index == n) return true;
        int flag = nums[index] > nums[index - 1];
        ++index;
        while (index < n) {
            if (nums[index] == nums[index - 1] ||
                flag && nums[index] > nums[index - 1]
                || !flag && nums[index] < nums[index - 1])
                    index++;
            else break;
        };
        return index == n;
    }
};