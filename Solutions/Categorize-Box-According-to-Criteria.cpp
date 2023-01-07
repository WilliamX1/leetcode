class Solution
{
  public:
    string categorizeBox(int length, int width, int height, int mass)
    {
        bool isBulky =
            length >= 1e4 || width >= 1e4 || height >= 1e4 || int64_t(length) * int64_t(width) * int64_t(height) >= 1e9;
        bool isHeavy = mass >= 100;
        if (isBulky && isHeavy)
            return "Both";
        else if (!isBulky && !isHeavy)
            return "Neither";
        else if (isBulky && !isHeavy)
            return "Bulky";
        else if (!isBulky && isHeavy)
            return "Heavy";
        return "";
    }
};