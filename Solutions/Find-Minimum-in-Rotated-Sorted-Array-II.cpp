#include <vector>
#include <stdio.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        /*二分搜索*/
        /*递归版本*/
        int left_idx = 0, right_idx = nums.size() - 1;
        int res = 2147483647;
        _findmin(left_idx, right_idx, res, nums);
        return res;
    };
    void _findmin(int left_idx, int right_idx, int& res, vector<int>& nums)
    {
        if (left_idx > right_idx) return;

        int mid_idx = (left_idx + right_idx) >> 1;
        if (nums[left_idx] < nums[mid_idx]) {
            if (res > nums[left_idx]) res = nums[left_idx];
            _findmin(mid_idx + 1, right_idx, res, nums);
        } else if (nums[mid_idx] < nums[right_idx]) {
            if (res > nums[mid_idx]) res = nums[mid_idx];
            _findmin(left_idx, mid_idx - 1, res, nums);
        } else {
            if (res > nums[mid_idx]) res = nums[mid_idx];
            _findmin(left_idx + 1, mid_idx - 1, res, nums);
            _findmin(mid_idx + 1, right_idx, res, nums);
        }
        return;
    }
};

int main()
{   
    Solution S;
    vector<int> v = {1,3,5};
    printf("%d", S.findMin(v));
    return 0;
}