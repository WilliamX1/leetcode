#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static bool compare(vector<int> A, vector<int> B) {
        if (A[0] == B[0]) return A[1] < B[1];
        else return A[0] < B[0];
    }
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        sort(logs.begin(), logs.end(), Solution::compare);
        vector<int> ans;
        for (int i = 0; i <= k; i++) ans.push_back(0);

        auto prev = logs.begin(), next = prev + 1;
        int tmp = 1;
        while (next != logs.end()) {
            if ((*prev).front() == (*next).front()) {
                if ((*prev).back() != (*next).back()) tmp++;
                prev = next++;
            } else {
                ans[tmp]++;
                tmp = 1;
                prev = next++;
            };
        };
        ans[tmp]++;
        ans.erase(ans.begin());
        return ans;
    };
};

int main()
{
    Solution S;
    vector<vector<int>> v = {{1,1},{1,2},{1,3}};
    S.findingUsersActiveMinutes(v, 3);
    return 0;
}