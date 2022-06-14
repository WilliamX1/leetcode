class Solution
{
  public:
    int getMaxLen(vector<int> &nums)
    {
        int len = nums.size();
        vector<int> pos(len, 0), neg(len, 0);
        if (nums[0] > 0)
            pos[0] = 1;
        else if (nums[0] < 0)
            neg[0] = 1;

        int ans = pos[0];
        for (int i = 1; i < len; i++)
        {
            if (nums[i] > 0)
            {
                pos[i] = pos[i - 1] + 1;
                neg[i] = neg[i - 1] > 0 ? neg[i - 1] + 1 : 0;
            }
            else if (nums[i] < 0)
            {
                pos[i] = neg[i - 1] > 0 ? neg[i - 1] + 1 : 0;
                neg[i] = pos[i - 1] + 1;
            }
            else
                pos[i] = neg[i] = 0;
            ans = max(ans, pos[i]);
        };
        return ans;
    }
};