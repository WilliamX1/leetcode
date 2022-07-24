#include <algorithm>
#include <cmath>
#include <iostream>
#include <stdio.h>
#include <unordered_map>
#include <vector>

using namespace std;

int calMinus(int left_j, int right_j, int up_i, int down_i, const vector<vector<int>> &rightDownMinus)
{
    // cout << "left_j: " << left_j << " right_j: " << right_j << " up_i: " << up_i << " down_i: " << down_i << endl;
    // cout << rightDownMinus[down_i][right_j] << endl;
    return rightDownMinus[down_i][right_j] - (up_i ? rightDownMinus[up_i - 1][right_j] : 0) -
           (left_j ? rightDownMinus[down_i][left_j - 1] : 0) +
           (up_i && left_j ? rightDownMinus[up_i - 1][left_j - 1] : 0);
};

int calPlus(int left_j, int right_j, int up_i, int down_i, const vector<vector<int>> &rightDownPlus)
{
    return rightDownPlus[down_i][right_j] - (up_i ? rightDownPlus[up_i - 1][right_j] : 0) -
           (left_j ? rightDownPlus[down_i][left_j - 1] : 0) +
           (up_i && left_j ? rightDownPlus[up_i - 1][left_j - 1] : 0);
}
int main()
{
    int n, m, C;
    cin >> n >> m >> C;
    vector<vector<int>> nums(n, vector<int>(m));
    char ch;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> ch;
            // cout << ch << ' ';
            if (ch == 'N')
                nums[i][j] = 1;
            else if (ch == 'T')
                nums[i][j] = -1;
            else
                nums[i][j] = 0;

            // cout << "i: " << i << " j: " << j << " nums[i][j]: " << nums[i][j] << endl;
        };

    vector<vector<int>> rightDownMinus(n, vector<int>(m)), rightDownPlus(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (i == 0 && j == 0)
            {
                rightDownMinus[i][j] = nums[i][j];
                rightDownPlus[i][j] = abs(nums[i][j]);
            }
            else if (i == 0)
            {
                rightDownMinus[i][j] = rightDownMinus[i][j - 1] + nums[i][j];
                rightDownPlus[i][j] = rightDownPlus[i][j - 1] + abs(nums[i][j]);
            }
            else if (j == 0)
            {
                rightDownMinus[i][j] = rightDownMinus[i - 1][j] + nums[i][j];
                rightDownPlus[i][j] = rightDownPlus[i - 1][j] + abs(nums[i][j]);
            }
            else
            {
                rightDownMinus[i][j] =
                    rightDownMinus[i - 1][j] + rightDownMinus[i][j - 1] - rightDownMinus[i - 1][j - 1] + nums[i][j];
                rightDownPlus[i][j] =
                    rightDownPlus[i - 1][j] + rightDownPlus[i][j - 1] - rightDownPlus[i - 1][j - 1] + abs(nums[i][j]);
            };

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //         cout << rightDownMinus[i][j] << ' ';
    //     cout << endl;
    // }

    vector<unordered_map<int, int>> left(m), right(m), up(n), down(n);

    //      left_j ... right_j ... m - 1
    // up_i
    // .
    // .
    // down_i
    // .
    // .
    // n - 1
    for (int right_j = 0; right_j < m; right_j++)
        for (int left_j = 0; left_j <= right_j; left_j++)
            for (int up_i = 0; up_i < n; up_i++)
                for (int down_i = up_i; down_i < n; down_i++)
                {
                    int minus = calMinus(left_j, right_j, up_i, down_i, rightDownMinus);
                    int plus = calPlus(left_j, right_j, up_i, down_i, rightDownPlus);
                    // cout << "i1: " << up_i << " i2: " << down_i << " j1: " << left_j << " j2: " << right_j
                    //      << " minus: " << minus << " plus: " << plus << endl;
                    left[right_j][minus] = max(left[right_j][minus], plus);
                };
    // cout << "\n\n";
    for (int left_j = m - 1; left_j >= 0; left_j--)
        for (int right_j = left_j; right_j < m; right_j++)
            for (int up_i = 0; up_i < n; up_i++)
                for (int down_i = up_i; down_i < n; down_i++)
                {
                    int minus = calMinus(left_j, right_j, up_i, down_i, rightDownMinus);
                    int plus = calPlus(left_j, right_j, up_i, down_i, rightDownPlus);
                    // cout << "i1: " << up_i << " i2: " << down_i << " j1: " << left_j << " j2: " << right_j
                    //      << " minus: " << minus << " plus: " << plus << endl;
                    right[left_j][minus] = max(right[left_j][minus], plus);
                };

    int ans = -1;
    for (int j = 0; j < m - 1; j++)
    {
        // unordered_map<int, int> &leftcount = left[j], &rightcount = right[j + 1];
        // int tt = min(j * j, (m - j) * (m - j));
        // tt *= tt;
        int tt = m * m;
        for (int k1 = -tt; k1 <= tt; k1++)
            for (int k2 = max(-tt, -k1 - C); k2 <= min(tt, C - k1); k2++)
                if (-C <= k1 + k2 && k1 + k2 <= C && left[j].count(k1) && right[j + 1].count(k2))
                {
                    // cout << "j: " << j << " k1: " << k1 << " k2: " << k2 << " " << leftcount[k1] << " "
                    //      << rightcount[k2] << endl;
                    ans = max(ans, left[j][k1] + right[j + 1][k2]);
                }
    };

    for (int down_i = 0; down_i < n; down_i++)
        for (int up_i = down_i; up_i >= 0; up_i--)
            for (int left_j = 0; left_j < m; left_j++)
                for (int right_j = left_j; right_j < m; right_j++)
                {
                    int minus = calMinus(left_j, right_j, up_i, down_i, rightDownMinus);
                    int plus = calPlus(left_j, right_j, up_i, down_i, rightDownPlus);
                    // cout << "i1: " << up_i << " i2: " << down_i << " j1: " << left_j << " j2: " << right_j
                    //      << " minus: " << minus << " plus: " << plus << endl;
                    up[down_i][minus] = max(up[down_i][minus], plus);
                };

    for (int up_i = n - 1; up_i >= 0; up_i--)
        for (int down_i = up_i; down_i < n; down_i++)
            for (int left_j = 0; left_j < m; left_j++)
                for (int right_j = left_j; right_j < m; right_j++)
                {
                    int minus = calMinus(left_j, right_j, up_i, down_i, rightDownMinus);
                    int plus = calPlus(left_j, right_j, up_i, down_i, rightDownPlus);
                    // cout << "i1: " << up_i << " i2: " << down_i << " j1: " << left_j << " j2: " << right_j
                    //      << " minus: " << minus << " plus: " << plus << endl;
                    down[up_i][minus] = max(down[up_i][minus], plus);
                };

    for (int i = 0; i < n - 1; i++)
    {
        // unordered_map<int, int> &upcount = up[i], &downcount = down[i + 1];
        // int tt = min(i * i, (n - i) * (n - i));
        // tt *= tt;
        int tt = n * n;
        for (int k1 = -tt; k1 <= tt; k1++)
            for (int k2 = max(-tt, -k1 - C); k2 <= min(tt, C - k1); k2++)
                if (-C <= k1 + k2 && k1 + k2 <= C && up[i].count(k1) && down[i + 1].count(k2))
                {
                    // cout << "j: " << i << " k1: " << k1 << " k2: " << k2 << " " << upcount[k1] << " " <<
                    // downcount[k2]
                    //      << endl;
                    ans = max(ans, up[i][k1] + down[i + 1][k2]);
                }
    }

    cout << ans << endl;

    return 0;
}