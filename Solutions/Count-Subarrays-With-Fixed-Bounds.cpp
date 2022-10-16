class Solution
{
  public:
    long long countSubarrays(vector<int> &nums, int minK, int maxK)
    {
        int n = nums.size();
        int nm = -1, mm = -1, NM = -1, MM = -1;

        long long ans = 0;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] < minK)
                nm = i;
            if (nums[i] == minK)
                mm = i;
            if (nums[i] > maxK)
                NM = i;
            if (nums[i] == maxK)
                MM = i;

            if (nums[i] == maxK)
                ans += (long long)max(0, mm - max(nm, NM));
            else if (nums[i] == minK)
                ans += (long long)max(0, MM - max(nm, NM));
            else if (mm >= 0 && MM >= 0)
                ans += (long long)max(0, min(mm, MM) - max(nm, NM));
        };

        return ans;
    }
};