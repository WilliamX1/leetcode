class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int> > pque;
        for (const int& num : nums) {
            pque.push(num);
        };

        while (k-- > 0) {
            int t = pque.top();
            pque.pop();

            t++;
            pque.push(t);
        };

        int64_t ans = 1, mod = 1e9 + 7;
        while (!pque.empty()) {
            int64_t t = pque.top();
            pque.pop();

            ans = (ans * t) % mod;
        };
        return ans;
    }
};