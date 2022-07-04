class Solution
{
  public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        k %= n;
        for (int i = 0; i < n - k; i++)
            nums.push_back(nums[i]);
        nums.assign(nums.begin() + n - k, nums.end());
    }
};