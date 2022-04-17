class Solution {
public:
    int giveGem(vector<int>& gem, vector<vector<int>>& operations) {
        for (const vector<int>& operation : operations) {
            int x = operation[0], y = operation[1];
            int give = gem[x] / 2;
            gem[x] -= give;
            gem[y] += give;
        };
        sort(gem.begin(), gem.end());
        return gem.back() - gem.front();
    }
};