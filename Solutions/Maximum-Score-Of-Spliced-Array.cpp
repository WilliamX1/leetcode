class Solution
{
  public:
    int maximumsSplicedArray(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            v[i] = nums1[i] - nums2[i];
        };
        int ans1 = 0, ans2 = 0, tot1 = 0, tot2 = 0;
        for (int i = 0; i < n; i++)
        {
            tot1 = min(0, tot1 + v[i]);
            tot2 = max(0, tot2 + v[i]);
            ans1 = min(ans1, tot1);
            ans2 = max(ans2, tot2);
        };
        int sum1 = accumulate(nums1.begin(), nums1.end(), 0) - ans1;
        int sum2 = accumulate(nums2.begin(), nums2.end(), 0) + ans2;
        // cout << sum1 << ' ' << sum2 << endl;
        return max(sum1, sum2);
    }
};