class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] + nums[i];
        
        map<int, int> m; m[0] = 1;
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            auto iter = m.find(prefix[i] - k);
            if (iter != m.end()) 
                ans += iter->second;
            iter = m.find(prefix[i]);
            if (iter != m.end())
                iter->second++;
            else m[prefix[i]] = 1;
        };
        return ans;
    }
};