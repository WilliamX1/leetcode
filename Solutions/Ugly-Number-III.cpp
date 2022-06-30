class Solution
{
  public:
    int64_t gcd(int64_t x, int64_t y)
    {
        int64_t tmp;
        while (y)
        {
            tmp = y;
            y = x % y;
            x = tmp;
        };
        return x;
    };
    int64_t lcm(int64_t x, int64_t y)
    {
        int64_t _gcd = gcd(x, y);
        return (x / _gcd) * (y / _gcd) * _gcd;
    };
    int nthUglyNumber(int n, int a, int b, int c)
    {
        int64_t left = 1, right = 2e9 + 7, aa = a, bb = b, cc = c;
        int64_t lcm_a_b = lcm(a, b), lcm_a_c = lcm(a, c), lcm_b_c = lcm(b, c), lcm_a_b_c = lcm(a, lcm_b_c);
        // cout << lcm_a_b << ' ' << lcm_a_c << ' ' << lcm_b_c << ' ' << lcm_a_b_c << endl;
        while (left <= right)
        {
            int64_t mid = (left + right) >> 1;

            int64_t cnt =
                mid / aa + mid / bb + mid / cc - mid / lcm_a_b - mid / lcm_a_c - mid / lcm_b_c + mid / lcm_a_b_c;
            // cout << "mid: " << mid << " cnt: " << cnt << endl;
            if (cnt < n)
                left = mid + 1;
            else
                right = mid - 1;
        };
        return left;
    }
};