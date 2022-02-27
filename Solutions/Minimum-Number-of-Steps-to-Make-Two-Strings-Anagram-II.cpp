class Solution {
public:
    int minSteps(string s, string t) {
        int ans = 0;
        unordered_map<char, int> smap, tmap;
        for (const char& ch : s)
            smap[ch]++;
        for (const char& ch : t)
            tmap[ch]++;
        for (int i = 0; i < 26; i++) {
            char ch = i + 'a';
            ans += abs(smap[ch] - tmap[ch]);
        };
        return ans;
    }
};