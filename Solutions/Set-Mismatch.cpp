class Solution
{
  public:
    vector<int> findErrorNums(vector<int> &nums)
    {
        int x = 0, n = nums.size();
        for (int i = 0; i < n; i++)
        {
            x ^= i ^ nums[i];
        };
        x ^= n;

        int lowbit = x & (-x);
        int num1 = 0, num2 = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] & lowbit)
                num1 ^= nums[i];
            else
                num2 ^= nums[i];
            if ((i + 1) & lowbit)
                num1 ^= i + 1;
            else
                num2 ^= i + 1;
        };

        for (const int &num : nums)
            if (num == num1)
            {
                return {num1, num2};
            };
        return {num2, num1};
    }
};