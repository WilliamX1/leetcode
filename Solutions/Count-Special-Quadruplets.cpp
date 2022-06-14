class Solution
{
  public:
    int countQuadruplets(vector<int> &nums)
    {
        int len = nums.size(), ans = 0;
        for (int i = 0; i < len; i++)
            for (int j = i + 1; j < len; j++)
                for (int k = j + 1; k < len; k++)
                {
                    int sum = nums[i] + nums[j] + nums[k];
                    for (int s = k + 1; s < len; s++)
                        if (nums[s] == sum)
                            ans++;
                };
        return ans;
    }
};