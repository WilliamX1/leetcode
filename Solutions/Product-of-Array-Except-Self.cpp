class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n + 1, 1), postfix(n + 1, 1);
        for (int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] * nums[i];
        for (int i = n - 1; i >= 0; i--)
            postfix[i] = postfix[i + 1] * nums[i];
        
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++)
            ans[i] = prefix[i] * postfix[i + 1];
        return ans;
    }
};