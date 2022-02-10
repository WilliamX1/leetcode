class Solution {
public:
    void getNext(int& i, int& j, int& dir, const int& n, const vector<vector<int>>& evergo) {
        switch (dir)
        {
        case 1: // 向右
            if (j < n - 1 && !evergo[i][j + 1]) j++;
            else {
                i++;
                dir = 2;
            };
            break;
        case 2: // 向下
            if (i < n - 1 && !evergo[i + 1][j]) i++;
            else {
                j--;
                dir = 3;
            };
            break;
        case 3: // 向左
            if (j > 0 && !evergo[i][j - 1]) j--;
            else {
                i--;
                dir = 4;
            };
            break;
        case 4: // 向上
            if (i > 0 && !evergo[i - 1][j]) i--;
            else {
                j++;
                dir = 1;
            };
            break;
        default:
            break;
        };
    };
    vector<vector<int>> generateMatrix(int n) {
        vector <vector<int>> ans(n, vector<int>(n, 0));
        int x = 0, y = 0, dir = 1;
        for (int i = 1; i <= n * n; i++) {
            ans[x][y] = i;
            getNext(x, y, dir, n, ans);
        };
        return ans;
    };
};