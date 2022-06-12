class Solution {
public:
    int dfs(const vector<int>& cookies, const int& n, const int i, vector<int>& cnts, const int& k) {
        if (i == n) return *max_element(cnts.begin(), cnts.end());

        int ans = 0x7ffffff;
        for (int j = 0; j < k; j++) {
            cnts[j] += cookies[i];
            ans = min(ans, dfs(cookies, n, i + 1, cnts, k));
            cnts[j] -= cookies[i];
        };
        return ans;
    };
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> cnts(k, 0);
        return dfs(cookies, cookies.size(), 0, cnts, k);
    }
};