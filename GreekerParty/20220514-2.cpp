/*************************************************************
    date: Spring 2022
    copyright: Bintao Yu
    DO NOT distribute this code without my permission.
**************************************************************/
    /********* Begin **********/
#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int n, m; cin >> n >> m;
    int* nums = new int[m];

    while (n-- > 0) {
        memset(nums, 0, sizeof(nums));
        for (int i = 0; i < m; i++)
            cin >> nums[i];
        int numi = nums[0], numj, idx = 1;
        while (idx < m && nums[idx] <= nums[idx - 1]) idx++;
        bool flag = false;
        if (idx < m) {
            numj = nums[idx];
            while (++idx < m) {
                if (nums[idx] > numj) {
                    numi = numj;
                    numj = nums[idx];
                } else if (nums[idx] < numi) {
                    flag = true;
                    break;
                } else continue;
            };
        };
        cout << (flag ? "True" : "False") << ' ';
    };

    return 0;
}
    /********** End **********/
// DO NOT USE THE STL LIBRARY.