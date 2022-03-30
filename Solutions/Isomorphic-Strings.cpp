class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.size();
        unordered_map<char, char> umap;
        unordered_map<char, bool> appear;
        for (int i = 0; i < n; i++) {
            if (umap.count(s[i]) && umap[s[i]] != t[i] || !umap.count(s[i]) && appear[t[i]]) return false;
            else {
                umap[s[i]] = t[i];
                appear[t[i]] = true;
            };
        };
        return true;
    }
};