class Solution
{
  public:
    double calculateTax(vector<vector<int>> &brackets, int income)
    {
        int64_t ans = 0, last = 0;
        for (const vector<int> &b : brackets)
        {
            int upper = b[0], percent = b[1];
            if (income >= upper)
            {
                ans += (upper - last) * percent;
            }
            else if (income > last)
            {
                ans += (income - last) * percent;
            }
            else
            {
            };
            last = upper;
        };
        return (double)ans / (double)(100);
    }
};