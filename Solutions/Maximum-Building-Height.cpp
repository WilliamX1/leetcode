#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static bool compare(vector<int> A, vector<int> B) {
        return A[0] < B[0];
    }
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        restrictions.push_back({1, 0});

        sort(restrictions.begin(), restrictions.end(), compare);

        int ans = 0;
        for (int right_idx = 1; right_idx < restrictions.size(); right_idx++)
        {
            int left_idx = right_idx - 1;
            int gap = abs(restrictions[right_idx][0] - restrictions[left_idx][0]);
            int dis = abs(restrictions[right_idx][1] - restrictions[left_idx][1]);
            if (gap - dis < 0) restrictions[right_idx][1] = restrictions[left_idx][0] + gap; 
            else ans = max(ans, (gap - dis) / 2 + max(restrictions[left_idx][1], restrictions[right_idx][1]));
        }
        ans = max(ans, n - restrictions[restrictions.size() - 1][0] + restrictions[restrictions.size() - 1][1]);
        return ans;
    }
};

int main()
{
    Solution S;
    vector<vector<int>> v = {{8,5},{9,0},{6,2},{4,0},{3,2},{10,0},{5,3},{7,3},{2,4}};
    S.maxBuilding(10, v);
    return 0;
}