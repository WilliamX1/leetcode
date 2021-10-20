#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>

using namespace std;

vector<vector<int>> xsort_arr;
vector<vector<int>> ysort_arr;

int64_t getDistance2(int64_t x1, int64_t y1, int64_t x2, int64_t y2) {
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
};

int64_t find(vector<vector<int>>& arr, int l, int r) {
    if (r - l == 1) return getDistance2(arr[l][0], arr[l][1], arr[r][0], arr[r][1]);

    int m = (l + r) >> 1;

    int64_t l_min = m > l ? find(arr, l, m) : 0x7fffffffffffffff, r_min = r > m + 1 ? find(arr, m + 1, r) : 0x7fffffffffffffff;
    int64_t ans = l_min < r_min ? l_min : r_min;
    int l_board = m - sqrt(ans) - 1, r_board = m + sqrt(ans) + 1;

    vector<vector<int>> tmp_arr;
    for (auto ele : ysort_arr) {
        if (l_board <= ele[0] && ele[0] <= r_board)
            tmp_arr.push_back(ele);
    };
    int n = tmp_arr.size();
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= 7; j++)
            if (i + j >= n) break;
            else {
                int64_t tmp_dis = getDistance2(tmp_arr[i][0], tmp_arr[i][1], tmp_arr[i + j][0], tmp_arr[i + j][1]);
                ans = tmp_dis < ans ? tmp_dis : ans;
            };
    };
    return ans;
};

int main()
{
    int n = 0;
    std::cin >> n;
    vector<vector<int>> ori_arr(n, vector<int>(2, 0));
    for (int i = 0; i < n; i++) {
        std::cin >> ori_arr[i][0] >> ori_arr[i][1];
        ori_arr[i][2] = i; /* 下标 */
    }
    
    xsort_arr.assign(ori_arr.begin(), ori_arr.end());
    ysort_arr.assign(ori_arr.begin(), ori_arr.end());
    /* 分别按照 x 轴和 y 轴排序 */
    sort(xsort_arr.begin(), xsort_arr.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    });
    sort(ysort_arr.begin(), ysort_arr.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    });

    std::cout << find(xsort_arr, 0, n - 1) << std::endl;
    return 0;
}