class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int ans = 0, tot;
        for (const string& sen : sentences) {
            tot = 0;
            for (const char& ch : sen)
                tot += ch == ' ';
            ans = max(ans, tot);
        };
        return ans + 1;
    }
};