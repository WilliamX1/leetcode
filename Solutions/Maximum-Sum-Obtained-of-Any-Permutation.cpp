class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        int64_t ans = 0, mod = 1e9 + 7, n = nums.size();
        sort(nums.begin(), nums.end(), greater<int>());
        vector<int64_t> minus(n + 1, 0);
        for (const vector<int>& req : requests) {
            minus[req[0]]++;
            minus[req[1] + 1]--;
        };
        for (int i = 1; i < n; i++)
            minus[i] += minus[i - 1];
        sort(minus.begin(), minus.end(), greater<int>());
        for (int i = 0; i < n; i++)
            ans = (ans + minus[i] * nums[i]) % mod;
        return ans;
    }
};