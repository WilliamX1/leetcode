class Solution
{
  public:
    vector<int> plusOne(vector<int> &digits)
    {
        vector<int> ans = digits;
        int n = digits.size(), i = n - 1;
        for (; i >= 0; i--)
        {
            if (digits[i] == 9)
            {
                ans[i] = 0;
            }
            else
            {
                ans[i]++;
                break;
            };
        };
        if (i < 0)
            ans.insert(ans.begin(), 1);
        return ans;
    }
};