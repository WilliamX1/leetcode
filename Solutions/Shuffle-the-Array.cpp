class Solution
{
  public:
    vector<int> shuffle(vector<int> &nums, int n)
    {
        vector<int> v(n << 1);
        for (int i = 0; i < n << 1; i += 2)
            v[i] = nums[i >> 1];
        for (int i = 1; i < n << 1; i += 2)
            v[i] = nums[(i >> 1) + n];
        return v;
    }
};