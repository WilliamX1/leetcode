class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size(), m = potions.size();
        vector<vector<int>> spellindex;
        for (int i = 0; i < n; i++)
            spellindex.push_back({spells[i], i});
        sort(spellindex.begin(), spellindex.end(), [](const vector<int>& v1, const vector<int>& v2) {
            return v1[0] < v2[0];
        });
        sort(potions.begin(), potions.end(), less<int>());
        vector<int> pairs(n, 0);
        for (int i = 0; i < n; i++) {
            int sp = spellindex[i][0], idx = spellindex[i][1];
            int64_t up = (success - 1) / (long long) (sp) + 1;
            if (up > 1e6) 
                continue;
            pairs[idx] = potions.size() - (lower_bound(potions.begin(), potions.end(), up) - potions.begin());
        };
        return pairs;
    }
};