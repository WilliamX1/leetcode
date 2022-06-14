class Solution
{
  public:
    long long countSubarrays(vector<int> &nums, long long k)
    {
        int n = nums.size();
        vector<long long> preSum(n);
        preSum[0] = (long long)nums[0];
        for (int i = 1; i < n; i++)
            preSum[i] = preSum[i - 1] + (long long)nums[i];

        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            int left = 0, right = i;
            while (left <= right)
            {
                int mid = (left + right) >> 1;
                long long mul = (preSum[i] - preSum[mid] + (long long)nums[mid]) * (long long)(i - mid + 1);
                if (mul >= k)
                    left = mid + 1;
                else
                    right = mid - 1;
            };
            ans += (long long)(i - left + 1);
        };
        return ans;
    }
};