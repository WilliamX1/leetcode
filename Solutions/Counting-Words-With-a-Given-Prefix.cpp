class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int tot = 0, size = pref.size();
        for (const string& word : words) {
            if (word.size() < size) continue;
            if (word.substr(0, size) == pref) tot++;
        };
        return tot;
    }
};