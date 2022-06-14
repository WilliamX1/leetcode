class Solution
{
  public:
    bool OK(int x)
    {
        while (x > 0)
        {
            if (x % 10 == 0)
                return false;
            else
                x /= 10;
        };
        return true;
    };
    vector<int> getNoZeroIntegers(int n)
    {
        for (int i = 1; i < n; i++)
        {
            int x = i, y = n - i;
            if (OK(x) && OK(y))
                return {x, y};
        };
        return {-1, -1};
    }
};