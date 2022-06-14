class Solution
{
  public:
    int add(int a, int b)
    {
        return b == 0 ? a : add(a ^ b, uint32_t(a & b) << 1);
    };
};