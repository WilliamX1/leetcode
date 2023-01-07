class Solution
{
  public:
    long long maxPower(vector<int> &stations, int r, int k)
    {
        long long left = 0, right = 1e18;
        int n = stations.size();

        vector<long long> count(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            count[max(i - r, 0)] += (long long)stations[i];
            count[min(i + r + 1, n)] -= (long long)stations[i];
        };

        while (left <= right)
        {
            vector<long long> count_copy = count;

            long long mid = (left + right) >> 1, remain_k = k;
            long long start = 0;

            for (int i = 0; i < n; i++)
            {
                count_copy[i] += i > 0 ? count_copy[i - 1] : 0;

                long long gap = mid - count_copy[i];
                if (gap > 0)
                {
                    remain_k -= gap;
                    count_copy[i] += gap;
                    count_copy[min(i + r + r + 1, n)] -= gap;
                };
                if (remain_k < 0)
                    break;
            };

            if (remain_k >= 0)
                left = mid + 1;
            else
                right = mid - 1;
        };
        return right;
    }
};