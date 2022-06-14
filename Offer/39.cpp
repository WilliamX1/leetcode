class Solution
{
  public:
    int majorityElement(vector<int> &nums)
    {
        int count = 1, len = nums.size(), temp = nums[0];
        for (int j = 1; j < len; j++)
        {
            if (nums[j] == temp)
            {
                count++;
            }
            else
            {
                count--;
            };
            if (!count)
            {
                count = 1;
                temp = nums[j];
            };
        };
        return temp;
    }
};