class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        vector<int> nums;
        int f1 = 0, f2 = 1, fn;
        do {
            fn = f1 + f2;
            nums.push_back(fn);
            f1 = f2;
            f2 = fn;
        } while (fn < 1e9);
        int ans = 0;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] <= k) {
                k -= nums[i];
                ans++;
            };
            if (k == 0) break;
        };
        return ans;
    }
};