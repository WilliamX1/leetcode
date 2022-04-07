class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int idx = 0;
        for (int i = 1; i <= n; i++) {
            ans.push_back("Push");
            if (i == target[idx]) idx++;
            else ans.push_back("Pop");
            if (idx == target.size()) break;
        };
        return ans;
    }
};