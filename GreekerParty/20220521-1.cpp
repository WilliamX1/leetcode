/*************************************************************
    date: Spring 2022
    DO NOT distribute this code without my permission.
**************************************************************/
/********* Begin **********/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, mod = 19260817;
    cin >> n;
    int start = 1e9, end = 0;
    vector<vector<int>> nums(n, vector<int>(4));
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i][0] >> nums[i][1] >> nums[i][2] >> nums[i][3];
        start = min(start, nums[i][0]);
        end = max(end, nums[i][1]);
    };

    int ans = 0;
    for (int i = start; i < end; i++)
    {
        int tmp = 0;
        for (vector<int> &num : nums)
            if (num[0] <= i && i < num[1])
                tmp = max(tmp, num[2] * num[3]);
        ans = (ans + tmp) % mod;
    };

    cout << ans << endl;
    return 0;
}
/********** End **********/
// DO NOT USE THE STL LIBRARY.