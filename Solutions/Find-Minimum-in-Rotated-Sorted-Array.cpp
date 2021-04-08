#include <vector>
#include <stdio.h>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        /*暴力查找*/
        // int size = nums.size();
        // int res = -1;
        // for (int i = 0; i < size; i++)
        //     if (nums[i] < res) res = nums[i];
        // return res;
        /*二分查找*/
        int left_idx = 0, right_idx = nums.size() - 1, mid_idx;
        int res = 2147483647;
        while (left_idx <= right_idx) {
            mid_idx = (left_idx + right_idx) >> 1;

            if (nums[left_idx] <= nums[mid_idx]) {
                if (nums[left_idx] < res) res = nums[left_idx];
                left_idx = mid_idx + 1;
            } else if (nums[mid_idx] <= nums[right_idx]) {
                if (nums[mid_idx] < res) res = nums[mid_idx];
                right_idx = mid_idx - 1;
            } else {
                if (nums[mid_idx] < res) res = nums[mid_idx];
                break;
            }
        }
        return res;
    }
};

int main()
{
    Solution S;
    vector<int> v = {2, 1};
    printf("%d", S.findMin(v));

    return 0;
}