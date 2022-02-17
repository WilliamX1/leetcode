class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        const int N = 1e5;
        vector<int> v(N + 1, 0);
        for (auto edge : edges) {
            v[edge[0]]++;
            v[edge[1]]++;
        };
        int idx = -1, ans = -1;
        for (int i = 1; i <= N; i++)
            if (v[i] > ans) {
                ans = v[i];
                idx = i;
            };
        return idx;
    }
};