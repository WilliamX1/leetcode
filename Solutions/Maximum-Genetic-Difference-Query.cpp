class Solution {
public:
    vector<int> maxGeneticDifference(vector<int>& parents, vector<vector<int>>& queries) {
        int len = queries.size();
        vector<int> ans(len, 0);
        for (int i = 0; i < len; i++)
        {
            int cur = queries[i][0];
            while (cur != -1)
            {
                ans[i] = max(ans[i], cur ^ queries[i][1]);
                cur = parents[cur];
            };
        };
        return ans;
    }
};