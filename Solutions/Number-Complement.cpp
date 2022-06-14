class Solution
{
  public:
    int findComplement(int num)
    {
        int n = num, mask = 1;
        while ((n >>= 1) > 0)
            mask = (mask << 1) | 1;

        return (~num) & mask;
    }
};