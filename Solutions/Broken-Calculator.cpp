class Solution
{
  public:
    int brokenCalc(int startValue, int target)
    {
        if (startValue == target)
            return 0;
        else if (startValue < target)
        {
            if (target & 1)
                return brokenCalc(startValue, target + 1) + 1;
            else
                return brokenCalc(startValue, target >> 1) + 1;
        }
        else
            return startValue - target;
    };
};