class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int, int> counts;
        int last = 0, next = 0, ans = 0, tmp = 0, n = nums.size();
        while (next < n) {
            while (next < n && !counts[nums[next]]) {
                tmp += nums[next];
                counts[nums[next]]++;
                next++;
            };
            ans = max(ans, tmp);

            if (next == n) break;
            while (last < n && counts[nums[next]]) {
                tmp -= nums[last];
                counts[nums[last]]--;
                last++;
            };
        };
        return ans;
    }
};