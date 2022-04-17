class Solution {
public:
    int dfs(const vector<vector<int>>& sons, const string& s, int root, int& ans) {
        int res = 0;
        for (const int& son : sons[root]) {
            int len = dfs(sons, s, son, ans);
            if (s[root] != s[son]) {
                ans = max(ans, len + res + 1);                
                res = max(res, len);
            } else {
                ans = max(ans, len);
            };
        };  
        return res + 1;
    };
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> sons(n);
        for (int i = 1; i < n; i++) {
            int son = i, pt = parent[i];
            sons[pt].push_back(son);
        };
        int ans = 0;
        ans = max(ans, dfs(sons, s, 0, ans));
        return ans;
    }
};