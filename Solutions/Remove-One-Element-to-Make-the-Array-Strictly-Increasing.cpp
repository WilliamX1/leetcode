class Solution
{
  public:
    bool canBeIncreasing(vector<int> &nums)
    {
        int idx = -1;
        for (int i = 1; i < nums.size(); i++)
            if (nums[i] <= nums[i - 1])
                if (idx != -1)
                    return false;
                else
                    idx = i;
        return idx == -1 || idx == 1 || idx == nums.size() - 1 || nums[idx + 1] > nums[idx - 1] ||
               nums[idx] > nums[idx - 2];
    }
};