class Solution
{
  public:
    int leastMinutes(int n)
    {
        return ceil(log(n) / log(2)) + 1;
    }
};