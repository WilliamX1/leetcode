#include <algorithm>
#include <cstring>
#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int main()
{
    int64_t t;
    scanf("%lld", &t);

    for (int64_t i = 0; i < t; i++)
    {
        int64_t n, flag = 0;
        scanf("%lld", &n);
        vector<int64_t> nums(n);
        for (int64_t j = 0; j < n; j++)
            scanf("%lld", &nums[j]);

        sort(nums.begin(), nums.end());

        int64_t tt1 = nums[0] + nums[1] + nums[2], tt2 = nums[n - 1] + nums[n - 2] + nums[n - 3],
                tt3 = nums[0] + nums[1] + nums[n - 1], tt4 = nums[n - 1] + nums[n - 2] + nums[0];
        bool flag1 = false, flag2 = false, flag3 = false, flag4 = false;
        for (int64_t j = 0; j < n; j++)
        {
            if (tt1 == nums[j])
                flag1 = true;
            if (tt2 == nums[j])
                flag2 = true;
            if (tt3 == nums[j])
                flag3 = true;
            if (tt4 == nums[j])
                flag4 = true;
        };
        if (flag1 && flag2 && flag3 && flag4)
            printf("YES\n");
        else
            printf("NO\n");
    };
    return 0;
}