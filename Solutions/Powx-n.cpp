class Solution
{
  public:
    double myPow(double x, int n)
    {
        double ans = 1.;

        int64_t nn = n;
        nn = abs(nn);
        while (nn)
        {
            if (nn & 1)
                ans *= x;
            nn >>= 1;
            x *= x;
        }
        return n < 0 ? 1. / ans : ans;
    }
};