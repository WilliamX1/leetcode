class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> smap, tmap;
        set<int> tset;
        for (const auto &ch : t) {
            tmap[ch]++;
            tset.insert(ch);
        };
        int tot = tset.size();
        int start = 0, end = -1, idx = -1;
        int ans_start = 0, ans_end = -1;
        while (++idx < s.size()) {
            char ch = s[idx];
            if (tmap[ch] && smap[ch] + 1 == tmap[ch]) tot--;
            smap[ch]++;
            if (!tot) {
                end = idx;
                while (start <= end && smap[s[start]] - 1 >= tmap[s[start]]) {
                    smap[s[start]]--;
                    start++;
                };
                ans_start = start;
                ans_end = end;
                break;
            };
        };

        if (ans_end == -1) return "";

        while (end < s.size()) {
            end++;
            smap[s[end]]++;
            while (start <= end && smap[s[start]] - 1 >= tmap[s[start]]) {
                smap[s[start]]--;
                start++;
            };
            if (end - start < ans_end - ans_start) {
                ans_start = start;
                ans_end = end;
            };
        };
        return s.substr(ans_start, ans_end - ans_start + 1);
    }
};