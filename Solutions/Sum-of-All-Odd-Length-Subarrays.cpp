class Solution
{
  public:
    int sumOddLengthSubarrays(vector<int> &arr)
    {
        int ans = 0, n = arr.size();
        for (int i = 0; i < n; i++)
        {
            int left = i, right = n - i - 1;
            ans += (left / 2 + 1) * (right / 2 + 1) * arr[i];
            ans += ((left + 1) / 2) * ((right + 1) / 2) * arr[i];
        };
        return ans;
    }
};