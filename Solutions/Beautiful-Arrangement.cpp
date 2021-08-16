class Solution {
public:
    int ans = 0;
    void dfs(int idx, int n, vector<bool> flag) {
        if (idx > n) {
            ans++;
            return;
        };
        for (int i = 1; i <= n; i++)
            if (!flag[i] && (flag[i] % i == 0 || i % flag[i] % i == 0))
            {
                flag[i] = true;
                dfs(idx + 1, n, flag);
                flag[i] = false;
            };
        return;
    };
    int countArrangement(int n) {
        vector<bool> flag(n + 1, false);
        dfs(1, n, flag);
    }
};