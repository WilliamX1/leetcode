class Solution {
public:
    int countGoodSubstrings(string s) {
        int n = s.size(), ans = 0;
        for (int i = 0; i < n - 2; i++) {
            unordered_map<char, bool> umap;
            bool flag = true;
            for (int j = 0; j < 3; j++) {
                if (umap[s[i + j]]) {
                    flag = false;
                    break;
                } else umap[s[i + j]] = true;
            };
            ans += flag;
        };
        return ans;
    }
};