#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if (!matrix.size() || !matrix[0].size()) return false;
        int m = matrix.size(), n = matrix[0].size(), x = 0, y = n - 1;
        while (true)
        {
            if (matrix[x][y] < target) {
                if (x < m - 1) x++;
                else return false;
            } else if (matrix[x][y] > target) {
                if (y > 0) y--;
                else return false;
            }
            else return true;
        };
        return false;
    }
};