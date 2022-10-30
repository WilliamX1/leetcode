class Solution
{
  public:
    int averageValue(vector<int> &nums)
    {
        int ans = 0, cnt = 0;
        for (const int &num : nums)
            if (num % 2 == 0 && num % 3 == 0)
            {
                ans += num;
                cnt++;
            };
        return cnt ? ans / cnt : 0;
    }
};