class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        int start = rounds[0] == 1 ? n : rounds[0] - 1;
        unordered_map<int, int> counts;
        for (int i = 0; i < rounds.size(); i++) {
            do {
                start = (start + 1);
                if (start > n) start = 1;
                counts[start]++;
            } while (start != rounds[i]);
        };
        vector<int> ans;
        int tot = 0;
        for (auto iter : counts) {
            if (ans.empty() || iter.second == tot) {
                ans.push_back(iter.first);
                tot = iter.second;
            }
            else if (iter.second > tot) {
                ans.clear();
                ans.push_back(iter.first);
                tot = iter.second;
            } else {};
        };
        sort(ans.begin(), ans.end());
        return ans;
    };
};