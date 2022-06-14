class Solution
{
  public:
    void sortColors(vector<int> &nums)
    {
        int left = 0, len = nums.size();
        for (int i = 0; i < len; i++)
        {
            if (nums[i] == 0)
                swap(nums[left++], nums[i]);
        };
        for (int i = left; i < len; i++)
        {
            if (nums[i] == 1)
                swap(nums[left++], nums[i]);
        };
        return;
    }
};