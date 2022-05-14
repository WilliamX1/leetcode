/*************************************************************
    date: Spring 2022
    copyright: Bintao Yu
    DO NOT distribute this code without my permission.
**************************************************************/
    /********* Begin **********/
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, m; cin >> n >> m;
    int * nums = new int[m];

    while (n-- > 0) {
        memset(nums, 0, sizeof(nums));

        vector<int> pre, post(m);
        for (int i = 0; i < m; i++) {
            cin >> nums[i];
            post[i] = nums[i];
        };

        sort(post.begin(), post.end());

        int count = 0;

        for (int i = 0; i < m; i++) {
            post.erase(lower_bound(post.begin(), post.end(), nums[i]));

            auto pre_iter = lower_bound(pre.begin(), pre.end(), nums[i]);
            if (pre_iter != pre.begin()) {
                --pre_iter;
                int left = *pre_iter;
                auto post_iter = lower_bound(post.begin(), post.end(), left);
                if (post_iter != post.begin()) {
                    ++count;
                };
            };

            pre_iter = lower_bound(pre.begin(), pre.end(), nums[i]);
            pre.insert(pre_iter, nums[i]);
        };
        cout << count << ' ';
    };

    return 0;
}
    /********** End **********/
// DO NOT USE THE STL LIBRARY.