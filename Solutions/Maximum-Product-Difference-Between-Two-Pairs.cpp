class Solution
{
  public:
    int maxProductDifference(vector<int> &nums)
    {
        sort(nums.begin(), nums.begin() + 4, greater<int>());
        int a = nums[0], b = nums[1], c = nums[2], d = nums[3];
        int len = nums.size();
        for (int i = 4; i < len; i++)
        {
            if (nums[i] > a)
            {
                b = a;
                a = nums[i];
            }
            else if (nums[i] > b)
                b = nums[i];
            else if (nums[i] < d)
            {
                c = d;
                d = nums[i];
            }
            else if (nums[i] < c)
                c = nums[i];
        };
        return a * b - c * d;
    }
};