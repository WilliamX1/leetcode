class Solution
{
  public:
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2)
    {
        int64_t left = 0, right = 2e9 + 7;

        int64_t c = 1;

        for (int i = 2; i <= min(divisor1, divisor2); i++)
            if (divisor1 % i == 0 && divisor2 % i == 0)
                c = i;
        c = (int64_t)(divisor1 / c) * (int64_t)(divisor2 / c) * c;
        // cout << c << endl;
        while (left <= right)
        {
            int64_t mid = (left + right) >> 1;

            int64_t cc0 = mid / c, cc1 = mid / divisor1 - cc0, cc2 = mid / divisor2 - cc0, cc3 = mid - cc0 - cc1 - cc2;
            // cout << cc0 << ' ' << cc1 << ' ' << cc2 << ' ' << cc3 << endl;
            cc3 -= uniqueCnt1 - cc2 > 0 ? uniqueCnt1 - cc2 : 0;
            cc3 -= uniqueCnt2 - cc1 > 0 ? uniqueCnt2 - cc1 : 0;
            if (cc3 >= 0)
                right = mid - 1;
            else
                left = mid + 1;
        };
        return left;
    }
};