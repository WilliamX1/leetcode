class Solution
{
  public:
    int lcd(int num1, int num2)
    {

        int tmp;
        while (num2)
        {
            tmp = num1 % num2;
            num1 = num2;
            num2 = tmp;
        };
        // cout << num1 << ' ';
        return num1;
    };
    int subarrayGCD(vector<int> &nums, int k)
    {
        int ans = 0, n = nums.size();

        for (int i = 0; i < nums.size(); i++)
        {
            ans += nums[i] == k;

            int j = i + 1, tmp = nums[i];
            while (j < nums.size() && tmp >= k)
            {
                tmp = lcd(tmp, nums[j]);
                ans += tmp == k;
                j++;
            };
        };

        return ans;
    }
};