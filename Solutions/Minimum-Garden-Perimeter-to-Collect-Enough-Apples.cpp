class Solution
{
  public:
    long long minimumPerimeter(long long neededApples)
    {
        /* 12 * n * n */
        int64_t ans = 0, sum = 0;
        while (sum < neededApples)
        {
            ans++;
            sum += 12 * ans * ans;
        };
        return ans * 8;
    }
};