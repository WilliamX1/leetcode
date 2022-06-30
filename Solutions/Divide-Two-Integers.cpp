class Solution
{
  public:
    int divide(int dividend, int divisor)
    {
        return dividend == INT_MIN && divisor == -1 ? INT_MAX : dividend / divisor;
    }
};