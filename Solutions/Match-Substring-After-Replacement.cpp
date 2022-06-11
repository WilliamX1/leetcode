class Solution {
public:
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
        unordered_map<char, unordered_map<char, bool>> ma;
        for (const vector<char>& v : mappings)
            ma[v[0]][v[1]] = true;

        int n = s.size(), m = sub.size();
        for (int i = 0; i + m <= n; i++) {
            bool flag = true;
            for (int j = 0; j < m; j++) {
                if (sub[j] != s[i + j] && !ma[sub[j]][s[i + j]]) {
                    flag = false;
                    break;
                };
            };
            if (flag) return true;
        };
        return false;
    }
};