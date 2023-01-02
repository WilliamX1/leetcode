class Solution
{
  public:
    int distinctPrimeFactors(vector<int> &nums)
    {
        set<int> s;
        for (int num : nums)
            for (int i = 2; i <= num; i++)
                while (num > 0 && num % i == 0)
                {
                    num /= i;
                    s.insert(i);
                }
        return s.size();
    }
};