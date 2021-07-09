class Solution {
public:
    int search(vector<int>& nums, int target) {
        int L = 0, R = nums.size() - 1, mid;
        while (L <= R) {
            mid = (L + R) >> 1;
            if (nums[mid] == target) return mid;
            else if (nums[mid] < target) L = mid + 1;
            else R = mid - 1;
        };
        return -1;
    }
};