#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        if (matrix.empty()) return 0;

        vector<int> vec;
        int row = matrix.size(), column = matrix[0].size();

        int res = INT_MIN;
        for (int left = 0; left < column; left++)
            for (int right = left; right < column; right++)
            {
                vec.clear();
                for (int idx = 0; idx < row; idx++) vec.push_back(accumulate(matrix[idx].begin() + left, matrix[idx].begin() + right + 1, 0));
                /* 前缀和 */
                for (int i = 1; i < vec.size(); i++) 
                    vec[i] += vec[i - 1];
                
                set<int> sum_set{0};
                /* 遍历并二分搜索 */
                for (int i = 0; i < vec.size(); i++) {
                    auto lb = sum_set.lower_bound(vec[i] - k);
                    if (lb != sum_set.end()) res = max(res, vec[i] - *lb);
                    sum_set.insert(vec[i]);
                };
            };
        return res;
    }
};

int main()
{
    Solution S;
    vector<vector<int>> v = {{2,2,-1}};
    S.maxSumSubmatrix(v, 3);
    return 0;
}