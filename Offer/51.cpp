class Solution
{
  private:
    int mergeSort(vector<int> &nums, int left, int right)
    {
        if (left >= right)
            return 0;

        int mid_idx = (left + right) >> 1;
        int ans = mergeSort(nums, left, mid_idx) + mergeSort(nums, mid_idx + 1, right);
        int left_idx = left, right_idx = mid_idx + 1;
        vector<int> tmp;
        while (left_idx <= mid_idx && right_idx <= right)
        {
            if (nums[left_idx] <= nums[right_idx])
            {
                tmp.push_back(nums[left_idx++]);
                ans += right_idx - (mid_idx + 1);
            }
            else
                tmp.push_back(nums[right_idx++]);
        };
        while (left_idx <= mid_idx)
        {
            tmp.push_back(nums[left_idx++]);
            ans += right_idx - (mid_idx + 1);
        };
        while (right_idx <= right)
        {
            tmp.push_back(nums[right_idx++]);
        };
        for (int i = 0; i < tmp.size(); i++)
        {
            nums[left + i] = tmp[i];
        };
        return ans;
    }

  public:
    int reversePairs(vector<int> &nums)
    {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};