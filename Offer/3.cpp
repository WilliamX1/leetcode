class Solution
{
  public:
    int findRepeatNumber(vector<int> &nums)
    {
        /* 简单比较，空间复杂度为O(N) */
        // int up = *max_element(nums.begin(), nums.end());
        // vector<bool> arr(up + 1, 0);
        // for (auto num : nums)
        //     if (arr[num]) return num;
        //     else arr[num] = true;
        // return -1;

        /* 标答解法 */
        int len = nums.size();
        for (int i = 0; i < len; i++)
            while (nums[i] != i)
                if (nums[i] != nums[nums[i]])
                    swap(nums[i], nums[nums[i]]);
                else
                    return nums[i];
        return -1;
    }
};