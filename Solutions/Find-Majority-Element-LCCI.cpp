class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = -1, count = 0;
        for (auto num : nums) {
            if (count == 0 || candidate == num) {
                candidate = num;
                count++;
            } else count--;
        };
        count = 0;
        for (auto num : nums) {
            if (candidate == num) count++;
        };
        return 2 * count > nums.size() ? candidate : -1;
    }
};