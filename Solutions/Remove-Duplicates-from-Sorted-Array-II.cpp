#include <vector>
#include <stdio.h>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        /*如果数组为空，则直接返回*/
        if (nums.size() == 0) return 0;

        int prev = nums.front();
        int cnt = 0;
        vector<int>::iterator iter = nums.begin();
        while (iter != nums.end()) {
            /*如果当前元素与上一个元素相等*/
            if (*iter == prev) {
                if (cnt <= 1) {
                    cnt++;
                    iter++;
                } else {
                    nums.erase(iter);
                }
            } else {
                prev = *iter;
                cnt = 1;
                iter++;
            }
        };
        return nums.size();
    };
};

int main()
{
    Solution S;
    vector<int> nums = {1, 1, 1, 2, 2, 2, 3, 3};
    int len = S.removeDuplicates(nums);

    for (int i = 0; i < len; i++)
        printf("%d ", nums[i]);

    return 0;
}