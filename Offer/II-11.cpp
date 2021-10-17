class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] + (nums[i] == 0 ? -1 : 1);
        int ans = 0;
        map<int, int> m; m[0] = 0;
        for (int i = 1; i <= n; i++){
            auto iter = m.find(prefix[i]);
            if (iter != m.end()) ans = max(ans, i - iter->second);
            else m[prefix[i]] = i;
        };
        return ans;
    }
};