/*************************************************************
    date: Spring 2022
    copyright: Bintao Yu
    DO NOT distribute this code without my permission.
**************************************************************/
/********* Begin **********/
#include <cstring>
#include <iostream>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int *nums = new int[m];
    while (n-- > 0)
    {
        memset(nums, 0, sizeof(nums));
        for (int i = 0; i < m; i++)
            cin >> nums[i];
        bool flag = false;
        for (int i = 1; i < m - 1; i++)
            if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1])
            {
                flag = true;
                break;
            };
        cout << (flag ? "True" : "False") << ' ';
    };
    cout << endl;

    return 0;
}
/********** End **********/
// DO NOT USE THE STL LIBRARY.