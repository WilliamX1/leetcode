#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int ans = 0;
    void dfs(vector<string>& arr, vector<bool> flag, int idx) {
        if (idx >= arr.size()) {
            ans = max(ans, accumulate(flag.begin(), flag. end(), 0));
            return;
        };

        dfs(arr, flag, idx + 1);

        for (auto str : arr[idx])
            if (flag[str - 'a']) return;
            else flag[str - 'a'] = true;

        dfs(arr, flag, idx + 1);
    };
public:
    int maxLength(vector<string>& arr) {
        vector<bool> flag(26, 0);
        dfs(arr, flag, 0);
        return ans;
    }
};

int main()
{
    Solution S;
    vector<string> arr = {"cha","r","act","ers"};
    std::cout << S.maxLength(arr);
    return 0;
}