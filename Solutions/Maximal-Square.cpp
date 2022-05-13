class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        matrix.insert(matrix.begin(), vector<char>(matrix[0].size(), '0'));
        for (int i = 0; i < matrix.size(); ++i)
            matrix[i].insert(matrix[i].begin(), '0');
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> sum(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) sum[i][j] = matrix[i][j] - '0';
                else if (i == 0) sum[i][j] = sum[i][j - 1] + matrix[i][j] - '0';
                else if (j == 0) sum[i][j] = sum[i - 1][j] + matrix[i][j] - '0';
                else sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + matrix[i][j] - '0';
            };
        };
        int edge = min(m, n);
        while (edge > 0) {
            for (int i = 1; i < m; i++) {
                for (int j = 1; j < n; j++) {
                    int ii = i + edge - 1, jj = j + edge - 1;
                    if (ii >= m || jj >= n) continue;
                    else if (sum[ii][jj] - sum[i - 1][jj] - sum[ii][j - 1] + sum[i - 1][j - 1] == edge * edge) {
                        // cout << i << " " << j << " " << ii << " " << jj << " " << edge << endl;
                        // cout << sum[ii][jj] << " " << sum[i - 1][j] << " " << sum[i][j - 1] << " " << sum[i - 1][j - 1] << endl;
                        return edge * edge;
                    };
                };
            };
            edge--;
        };
        return 0;
    }
};