class Solution
{
  public:
    vector<int> selfDividingNumbers(int left, int right)
    {
        vector<int> ans;
        for (int i = left; i <= right; i++)
        {
            int num = i, flag = 1;
            while (num > 0)
            {
                if ((num % 10) != 0 && (i % (num % 10)) == 0)
                    num /= 10;
                else
                {
                    flag = 0;
                    break;
                };
            };
            if (flag)
                ans.push_back(i);
        };
        return ans;
    }
};