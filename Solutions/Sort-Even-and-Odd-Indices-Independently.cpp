class Solution
{
  public:
    vector<int> sortEvenOdd(vector<int> &nums)
    {
        vector<int> odd, even;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (i & 1)
                odd.push_back(nums[i]);
            else
                even.push_back(nums[i]);
        };
        sort(odd.begin(), odd.end(), greater<int>());
        sort(even.begin(), even.end(), less<int>());
        vector<int> ans(n, 0);
        int odd_idx = 0, even_idx = 0;
        for (int i = 0; i < n; i++)
        {
            if (i & 1)
                ans[i] = odd[odd_idx++];
            else
                ans[i] = even[even_idx++];
        };
        return ans;
    }
};