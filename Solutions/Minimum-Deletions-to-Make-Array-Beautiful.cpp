class Solution
{
  public:
    int minDeletion(vector<int> &nums)
    {
        vector<int> v;
        v.push_back(nums[0]);
        int tot = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == nums[i - 1] && (v.size() & 1))
            {
                tot++;
            }
            else
                v.push_back(nums[i]);
        };
        if (v.size() & 1)
            tot++;
        return tot;
    }
};