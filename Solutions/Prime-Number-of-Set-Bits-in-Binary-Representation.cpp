class Solution
{
  public:
    bool is_prime(int x)
    {
        if (x <= 1)
            return false;
        for (int i = 2; i < x; i++)
            if (x % i == 0)
                return false;
        return true;
    };
    int cal(int x)
    {
        int ans = 0;
        while (x > 0)
        {
            ans += x & 1;
            x >>= 1;
        };
        return ans;
    };
    int countPrimeSetBits(int left, int right)
    {
        int ans = 0;
        for (int i = left; i <= right; i++)
        {
            ans += is_prime(cal(i));
        };
        return ans;
    }
};