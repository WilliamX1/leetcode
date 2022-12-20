class Solution
{
  public:
    int smallestValue(int n)
    {
        int sum = 0, ori_n = n;

        int cur = 2;
        while (cur <= n)
        {
            if (n % cur)
                cur++;
            else
            {
                sum += cur;
                n /= cur;
            };
        };

        return sum == ori_n ? sum : smallestValue(sum);
    }
};