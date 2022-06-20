class Solution
{
  public:
    int minSpeedOnTime(vector<int> &dist, double hour)
    {
        int left = 1, right = 1e7 + 1, n = dist.size();
        long long hh = llround(hour * 100);

        if (hh <= (n - 1) * 100)
            return -1;
        while (left <= right)
        {
            int mid = (left + right) >> 1;
            long long t = 0;
            for (int i = 0; i < n - 1; i++)
                t += (dist[i] - 1) / mid + 1;
            t *= mid;
            t += dist[n - 1];
            if (t * 100 <= hh * mid)
            {
                right = mid - 1;
            }
            else
                left = mid + 1;
        };
        return left;
    }
};