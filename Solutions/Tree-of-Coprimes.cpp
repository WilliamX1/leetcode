class Solution {
public:
    unordered_map<int, vector<int>> father2sons;
    unordered_map<int, vector<int>> gcdlist;

    void dfs(const vector<int>& nums, vector<vector<int>>& ans, const int& root, vector<vector<int>>& distance, const int& up) {
        if (father2sons[root].empty()) 
            return;

        int oriroot0 = distance[nums[root]][0], oriroot1 = distance[nums[root]][1];
        for (int i = 1; i <= up; i++)
            if (distance[i][0])
                distance[i][0]++;

        distance[nums[root]][0] = 1;
        distance[nums[root]][1] = root;

        for (int& son : father2sons[root]) {
            int sonnum = nums[son];
            for (int& num : gcdlist[sonnum]) {
                if (distance[num][0] > 0 && (ans[son][0] == -1 || distance[num][0] < ans[son][0])) {
                    ans[son][0] = distance[num][0];
                    ans[son][1] = distance[num][1];
                }
            }
            dfs(nums, ans, son, distance, up);
        };

        for (int i = 1; i <= up; i++)
            if (distance[i][0])
                distance[i][0]--;
        distance[nums[root]][0] = oriroot0;
        distance[nums[root]][1] = oriroot1;
    };
    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
        unordered_map<int, vector<int> > edgelist;

        int n = nums.size();
        vector<int> flags(n, false);
        for (vector<int>& edge : edges) {
            int x = edge[0], y = edge[1];
            edgelist[x].push_back(y);
            edgelist[y].push_back(x);;
        };

        queue<int> que;
        que.push(0);
        flags[0] = true;
        while (!que.empty()) {
            int idx = que.front();
            que.pop();

            for (int& pos_son : edgelist[idx])
                if (!flags[pos_son]) {
                    flags[pos_son] = true;
                    father2sons[idx].push_back(pos_son);
                    que.push(pos_son);
                };
        };

        int up = *max_element(nums.begin(), nums.end());

        for (int i = 1; i <= up; ++i) {
            for (int j = i; j <= up; ++j) {
                bool flag = true;
                for (int k = 2; k <= min(i, j); ++k) {
                    if (i % k == 0 && j % k == 0) {
                        flag = false;
                        break;
                    };
                };
                if (flag) {
                    gcdlist[i].push_back(j);
                    gcdlist[j].push_back(i);
                };
            }
        }

        vector<vector<int>> ans(n, vector<int>(2, -1));
        vector<vector<int>> distance(up + 1, vector<int>(2, -1));
        dfs(nums, ans, 0, distance, up);

        vector<int> res(n);
        for (int i = 0; i < n; i++)
            res[i] = ans[i][1];
        return res;
    }
};