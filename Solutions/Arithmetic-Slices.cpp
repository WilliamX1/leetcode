class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int len = nums.size();
        vector<int> minus;
        for (int i = 1; i < len; i++)
            minus.push_back(nums[i] - nums[i - 1]);
        int ans = 0, cur = minus[0], cnt = 1;
        for (int i = 1; i < len - 1; i++)
            if (cur != minus[i]) {
                ans += cnt * (cnt - 1) / 2;
                cur = minus[i];
                cnt = 1;
            } else cnt++;
        ans += cnt * (cnt - 1) / 2;
    }
};