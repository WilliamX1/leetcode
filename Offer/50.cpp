class Solution {
public:
    char firstUniqChar(string s) {
        int len = s.size();
        unordered_map<char, int> m;
        for (int i = 0; i < len; i++)
            m[s[i]] = m.find(s[i]) == m.end() ? 1 : m[s[i]] + 1;
        for (int i = 0; i < len; i++)
            if (m[s[i]] == 1) return s[i];
        return ' ';
    }
};