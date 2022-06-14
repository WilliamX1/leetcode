class Solution
{
  public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1;
        while (left < right)
        {
            while (left < right && nums[left] + nums[right] > target)
                right--;
            if (left != right && nums[left] + nums[right] == target)
                return {nums[left], nums[right]};
            else
                left++;
        };
        return vector<int>();
    }
};