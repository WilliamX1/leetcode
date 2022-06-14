class Solution
{
  public:
    int minStartValue(vector<int> &nums)
    {
        int m = 1e9, sum = 0;
        for (const int &num : nums)
        {
            sum += num;
            m = min(m, sum);
        };
        m = max(1, 1 - m);
        return m;
    }
};