class Solution
{
  public:
    bool sumOfNumberAndReverse(int num)
    {
        for (int i = 0; i <= num; i++)
        {
            string str = to_string(i);
            reverse(str.begin(), str.end());
            if (stoll(str) + i == num)
                return true;
        };
        return false;
    }
};