#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findGCD(vector<int>& nums) {
        int max = *max_element(nums.begin(), nums.end());
        int min = *min_element(nums.begin(), nums.end());
        while (min >= 1)
        {
            max %= min;
            swap(min, max);
        };
        return max;
    }
};