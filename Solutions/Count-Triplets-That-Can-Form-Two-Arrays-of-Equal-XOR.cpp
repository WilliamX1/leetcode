class Solution
{
  public:
    int countTriplets(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> prefix(n, 0);
        prefix[0] = arr[0];
        for (int i = 1; i < n; i++)
        {
            prefix[i] = prefix[i - 1] ^ arr[i];
        };
        int ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                for (int k = j; k < n; k++)
                {
                    if ((prefix[j - 1] ^ prefix[i] ^ arr[i]) == (prefix[k] ^ prefix[j] ^ arr[j]))
                        ans++;
                };
        return ans;
    }
};