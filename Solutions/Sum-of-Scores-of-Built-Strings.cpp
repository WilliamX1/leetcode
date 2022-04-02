class Solution {
public:
    long long sumScores(string s) {
        unordered_map<char, int64_t> umap;
        int64_t tot = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            umap[s[i]]++;
            if (s[i] == s[0]) 
                tot += umap[s[i]];
            cout << tot <<  ' ';
        };
        return tot;
    }
};