#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int max;
    vector<int> max_idxs;
    void dfs(vector<int>& tasks, vector<bool>& flags, const int& n, vector<int> idxs, int target) {
        if (target < max) {
            max_idxs = idxs;
            max = target;
        };
        if (max == 0) return;
        for (int i = 0; i < n; i++)
        {
            if (!flags[i] && target >= tasks[i]) {
                flags[i] = true;
                idxs.push_back(i);
                dfs(tasks, flags, n, idxs, target - tasks[i]);
                idxs.pop_back();
                flags[i] = false;
            };
        };
    };
    int minSessions(vector<int>& tasks, int sessionTime) {
        int n = tasks.size(), ans = 0;
        vector<bool> flags(n, false);
        vector<int> idxs;
        sort(tasks.begin(), tasks.end(), greater<int>());
        while (accumulate(flags.begin(), flags.end(), 0) < n && ++ans) {
            max = sessionTime;
            max_idxs.clear();
            dfs(tasks, flags, n, idxs, sessionTime);
            cout << max << endl;
            for (auto idx : max_idxs) {
                flags[idx] = true;
            };
        };
        
        return ans;
    }
};

int main()
{
    vector<int> v = {2,3,3,4,4,4,5,6,7,10};
    Solution S;
    S.minSessions(v, 12);
    return 0;
}