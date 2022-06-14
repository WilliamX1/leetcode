class Solution
{
  public:
    int threeSumMulti(vector<int> &arr, int target)
    {
        int n = arr.size(), tot = 0, mod = 1e9 + 7;
        unordered_map<int, int> twice;
        for (int i = 0; i < n; i++)
        {
            tot = (tot + twice[target - arr[i]]) % mod;
            for (int j = i - 1; j >= 0; j--)
                twice[arr[i] + arr[j]]++;
        };
        return tot;
    }
};