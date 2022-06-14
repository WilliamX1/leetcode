class Solution
{
  public:
    int maximumSum(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> pre(n), post(n);
        pre[0] = arr[0];
        for (int i = 1; i < n; i++)
            pre[i] = max(0, pre[i - 1]) + arr[i];
        post[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--)
            post[i] = max(0, post[i + 1]) + arr[i];

        int ans = -1e9;
        for (int i = 0; i < n; i++)
            ans = max(ans, pre[i]);
        for (int i = 1; i < n - 1; i++)
        {
            ans = max(ans, pre[i - 1] + post[i + 1]);
        };
        return ans;
    }
};