class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> ans;
        int tot = 0, ch = 0, n = s.length();
        for (int i = 0; i < n; i++) {
            if (ch == s[i]) tot++;
            else if (tot >= 3) {
                ans.push_back({i - tot, i - 1});
                ch = s[i];
                tot = 1;
            } else {
                ch = s[i];
                tot = 1;
            };
        };
        if (tot >= 3)
            ans.push_back({n - tot, n - 1});
        return ans;
    }
};