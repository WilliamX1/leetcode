class Solution {
public:
    int minimumTime(string s) {
        int n = s.size(), MAX = n * 10;
        vector<int> pre(n, MAX), post(n + 1, MAX);
        pre[0] = s[0] == '1';
        for (int i = 1; i < n; i++)
            pre[i] = s[i] == '1' ? min(i + 1, pre[i - 1] + 2) : pre[i - 1];
        post[n] = 0;
        post[n - 1] = s[n - 1] == '1';
        for (int i = n - 2; i >= 0; i--) 
            post[i] = s[i] == '1' ? min(n - i, post[i + 1] + 2) : post[i + 1];
        int ans = MAX;
        for (int i = 0; i < n; i++) 
            ans = min(ans, pre[i] + post[i + 1]);
        return ans;
    }
};