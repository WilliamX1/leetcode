class Solution
{
  public:
    int minimumPartition(string s, int k)
    {
        int64_t ans = 0, cur = 0;
        for (char ch : s)
        {
            if (ch - '0' > k)
                return -1;
            else
            {
                cur = cur * 10LL + (long long)(ch - '0');
                if (cur > (long long)k)
                {
                    ans++;
                    cur = ch - '0';
                };
            };
        };
        return ans + 1;
    }
};