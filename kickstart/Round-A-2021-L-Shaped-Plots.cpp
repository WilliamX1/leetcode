#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int T; cin >> T;
    for (int i = 1; i <= T; i++) {
        int R, C; cin >> R >> C;
        vector< vector<int> > v(R, vector<int>(C, 0));
        for (int j = 0; j < R; j++)
            for (int k = 0; k < C; k++)
                cin >> v[j][k];
        
        vector< vector<int> > prefix_row(R, vector<int>(C, 0));
        for (int j = 0; j < R; j++)
            for (int k = 0; k < C; k++) {
                if (k == 0) prefix_row[j][0] = v[j][0];
                else prefix_row[j][k] = v[j][k] == 1 ? prefix_row[j][k - 1] + v[j][k] : 0;
            };
        vector< vector<int> > prefix_col(R, vector<int>(C, 0));
        for (int k = 0; k < C; k++)
            for (int j = 0; j < R; j++) {
                if (j == 0) prefix_col[0][k] = v[0][k];
                else prefix_col[j][k] = v[j][k] == 1 ? prefix_col[j - 1][k] + v[j][k] : 0;
            };
        
        int ans = 0;
        for (int j = 0; j < R; j++)
            for (int k = 0; k < C; k++) {
                if (prefix_row[j][k] > 1 && prefix_col[j][k] > 1) {
                    ans += min(prefix_row[j][k] >> 1, prefix_col[j][k]) + min(prefix_col[j][k] >> 1, prefix_row[j][k]) - 2;
                };
            };
        cout << "Case #" << i << ": " << ans << endl;
    };
    return 0;
};