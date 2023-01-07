class Solution
{
  public:
    int xorBeauty(vector<int> &nums)
    {
        int ret = 0;
        for (int &num : nums)
            ret ^= num;
        return ret;
    }
};