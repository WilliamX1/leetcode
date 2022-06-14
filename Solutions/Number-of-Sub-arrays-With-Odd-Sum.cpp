class Solution
{
  public:
    int numOfSubarrays(vector<int> &arr)
    {
        int odd = 0, even = 0, mod = 1e9 + 7, tot_odd = 0, tot_even = 0;
        for (auto num : arr)
        {
            int last_odd = odd, last_even = even;
            if (num & 1)
            {
                even = last_odd;
                odd = last_even + 1;
            }
            else
            {
                odd = last_odd;
                even = last_even + 1;
            };
            odd %= mod;
            even %= mod;
            tot_odd = (tot_odd + odd) % mod;
        };
        return tot_odd;
    }
};