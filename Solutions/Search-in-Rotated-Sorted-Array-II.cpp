#include <stdio.h>
#include <vector>

using namespace std;

class Solution
{
  public:
    bool search(vector<int> &nums, int target)
    {
        /*暴力解法遍历数组*/
        // vector<int>::iterator iter = nums.begin();
        // while (iter != nums.end()) {
        //     if (*iter == target) return true;
        //     iter++;
        // };
        // return false;
        /*高级二分搜索算法*/
        int left_idx = 0, right_idx = nums.size() - 1, mid_idx;
        while (left_idx <= right_idx)
        {
            mid_idx = (left_idx + right_idx) >> 1;
            if (nums[mid_idx] == target || nums[left_idx] == target || nums[right_idx] == target)
                return true;
            else if (nums[left_idx] < nums[mid_idx])
            {
                if (nums[left_idx] < target && target < nums[mid_idx])
                {
                    left_idx = left_idx + 1;
                    right_idx = mid_idx - 1;
                }
                else
                {
                    left_idx = mid_idx + 1;
                    right_idx = right_idx - 1;
                }
            }
            else if (nums[mid_idx] < nums[right_idx])
            {
                if (nums[mid_idx] < target && target < nums[right_idx])
                {
                    left_idx = mid_idx + 1;
                    right_idx = right_idx - 1;
                }
                else
                {
                    left_idx = left_idx + 1;
                    right_idx = mid_idx - 1;
                }
            }
            else
            {
                left_idx++;
                right_idx--;
            };
        }
        return false;
    }
};

int main()
{
    Solution S;
    vector<int> v = {1};
    printf("%d", S.search(v, 1));

    return 0;
}