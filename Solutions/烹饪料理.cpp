class Solution {
public:
    int _perfectMenu(vector<int> materials, const vector<vector<int>>& cookbooks, const vector<vector<int>>& attribute, int index, int n, int cur, int limit) {
        int ans = -1;
        if (limit <= 0) ans = cur;
        if (index == n) return ans;
        ans = max(ans, _perfectMenu(materials, cookbooks, attribute, index + 1, n, cur, limit));
        for (int i = 0; i < cookbooks[index].size(); i++) {
            materials[i] -= cookbooks[index][i];
            if (materials[i] < 0) return ans;
        };
        ans = max(ans, _perfectMenu(materials, cookbooks, attribute, index + 1, n, cur + attribute[index][0], limit - attribute[index][1]));
        return ans;  
    };
    int perfectMenu(vector<int>& materials, vector<vector<int>>& cookbooks, vector<vector<int>>& attribute, int limit) {
        return _perfectMenu(materials, cookbooks, attribute, 0, cookbooks.size(), 0, limit);
    }
};