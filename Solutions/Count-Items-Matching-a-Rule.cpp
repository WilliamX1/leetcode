class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int tot = 0, idx = -1;
        if (ruleKey == "type") idx = 0;
        else if (ruleKey == "color") idx = 1;
        else if (ruleKey == "name") idx = 2;
        else {};
        for (const vector<string>& item : items) {
            if (item[idx] == ruleValue)
                tot++;
        };
        return tot;
    }
};