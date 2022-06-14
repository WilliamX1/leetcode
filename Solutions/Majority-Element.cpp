class Solution
{
  public:
    int majorityElement(vector<int> &nums)
    {
        int vote = 1, ans = nums.front(), size = nums.size();
        for (int i = 1; i < size; i++)
        {
            vote += nums[i] == ans ? 1 : -1;

            if (vote < 0)
            {
                ans = nums[i];
                vote = 1;
            };
        };
        return ans;
    }
};