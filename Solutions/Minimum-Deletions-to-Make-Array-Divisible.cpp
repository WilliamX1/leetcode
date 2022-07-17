class Solution
{
  public:
    int gcd(int x, int y)
    {
        while (x)
        {
            int tmp = x;
            x = y % tmp;
            y = tmp;
        };
        return y;
    };
    int minOperations(vector<int> &nums, vector<int> &numsDivide)
    {
        int nn = numsDivide[0];
        for (const int &num : numsDivide)
            nn = gcd(nn, num);

        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
            if (nn % nums[i] == 0)
                return i;
        return -1;
    }
};