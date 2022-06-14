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
    int N;
    cin >> N;
    vector<vector<int>> nums(N, vector<int>(3));
    for (int i = 0; i < N; i++)
        cin >> nums[i][0] >> nums[i][1] >> nums[i][2];

    const int up = 500;
    vector<int> dp(up + 1, 0);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= up - nums[i][1]; j++)
        {
            dp[j + nums[i][1]] = max(dp[j + nums[i][1]], dp[j] + nums[i][2]);
        };
    };
    cout << *max_element(dp.begin(), dp.end()) << endl;
    return 0;
}
/********** End **********/
// DO NOT USE THE STL LIBRARY.