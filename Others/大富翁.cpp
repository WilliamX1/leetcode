#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int main()
{
    int64_t n;
    cin >> n;

    vector<int64_t> nums(n);
    for (int64_t i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
        nums[i] += i;
    };

    int64_t left = 0, right = nums[0], M = 0;

    while (left < n)
    {
        while (left <= right && left < n)
        {
            M = max(M, nums[left]);
            left++;
        };
        if (right == M)
            break;
        else
            right = M;
        // cout << "left: " << left << " right: " << right << endl;
    };
    cout << right + 1 << endl;

    return 0;
}