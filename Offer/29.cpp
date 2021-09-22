#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = m > 0 ? matrix[0].size() : 0, x = 0, y = -1;
        vector<int> res;
        while (m > 0 && n > 0) {
            bool flag = false;
            for (int j = 0; j < n; j++)
            {
                y++;
                res.push_back(matrix[x][y]);
                flag = true;
            };
            if (!flag) break;
            else flag = false;
            for (int i = 0; i < m - 1; i++)
            {
                x++;
                res.push_back(matrix[x][y]);
                flag = true;
            };
            if (!flag) break;
            else flag = false;
            for (int j = 0; j < n - 1; j++)
            {
                y--;
                res.push_back(matrix[x][y]);
                flag = true;
            };
            if (!flag) break;
            else flag = false;
            for (int i = 0; i < m - 2; i++)
            {
                x--;
                res.push_back(matrix[x][y]);
                flag = true;
            };
            if (!flag) break;
            else flag = false;
            n -= 2; m -= 2;
        };
        return res;
    }
};