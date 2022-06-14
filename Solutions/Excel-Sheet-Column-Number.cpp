class Solution
{
  public:
    int titleToNumber(string columnTitle)
    {
        int64_t len = columnTitle.size(), res = 0, cur = 1;
        for (int i = len - 1; i >= 0; i--)
        {
            res += (columnTitle[i] - 'A' + 1) * cur;
            cur *= 26;
        };
        return res;
    }
};