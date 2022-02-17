class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {
        vector< vector< vector<double> > > v(n, vector<vector<double>>(n, vector<double>(k + 1, 1.0)));

        for (int i = 1; i <= k; i++) 
            for (int j = 0; j < n; j++)
                for (int h = 0; h < n; h++) {
                    double tot = 0.0;
                    for (int s = -2; s <= 2; s++)
                        for (int m = -2; m <= 2; m++)
                            if (abs(s) != abs(m) && s != 0 && m != 0 && 0 <= j + s && j + s < n && 0 <= h + m && h + m < n)
                                tot += v[j + s][h + m][i - 1];
                    v[j][h][i] = 0.125 * tot;
                };
        return v[row][column][k];
    }
};