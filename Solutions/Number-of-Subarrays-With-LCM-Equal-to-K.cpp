class Solution
{
  public:
    int gcd(int a, int b)
    {
        int tmp;
        while (b)
        {
            tmp = a % b;
            a = b;
            b = tmp;
        };
        return a;
    }
    int lcm(int a, int b)
    {
        int g = gcd(a, b);
        return g * (a / g) * (b / g);
    };
    int subarrayLCM(vector<int> &nums, int k)
    {
        int n = nums.size(), ans = 0;
        for (int i = 0; i < n; i++)
        {
            int m = 1;
            for (int j = i; j < n; j++)
            {
                m = lcm(m, nums[j]);
                if (m == k)
                    ans++;
                else if (m > k)
                    break;
            };
        };
        return ans;
    }
};