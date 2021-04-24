#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool recurse(bool* flag, vector<int> arr, int batchSize, int cur_idx, int target, int& ans) {
        if (arr[cur_idx] == target) {
            ans++;
            flag[cur_idx] = true;
            return true;
        } else if (arr[cur_idx] > target) return false;

        for (int i = cur_idx - 1; i >= 0; i--) {
            if (flag[i] == false && recurse(flag, arr, batchSize, i, (target - arr[cur_idx]) % batchSize, ans)) {
                flag[cur_idx] = true;
                return true;
            };
        };
        return false;
    };
    int maxHappyGroups(int batchSize, vector<int>& groups) {
        vector<int> arr;
        for (auto i = 0; i < groups.size(); i++)
            arr.push_back(groups[i] % batchSize);
        sort(arr.begin(), arr.end());

        int ans = 0;
        for (auto i = arr.begin(); i != arr.end() && *i == 0; ) {
            ans++;
            arr.erase(i);
        };
        if (arr.empty()) return ans;

        ans++;
        bool flag[arr.size()]; memset(flag, 0, sizeof(flag));
        for (int i = arr.size() - 1; i >= 0; i--)
            if (flag[i] == false) recurse(flag, arr, batchSize, i, batchSize, ans);
        
        for (int i = 0; i < arr.size(); i++)
            if (flag[i] == false) return ans;

        return ans - 1;
    }
};

int main()
{
    Solution S;
    vector<int> v = {145326640,622724151,591814792,827053040,111964428,344376875,42023891,436582274,78590835,408269112,930041188,846233596,158192647,889601516,134236253,366035866,123146762};
    for (int i = 0; i < v.size(); i++)
        v[i] %= 7;
    printf("%d", S.maxHappyGroups(7, v));
    return 0;
}