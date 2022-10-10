class Solution
{
  public:
    int minimizeXor(int num1, int num2)
    {
        int cnt = 0;
        while (num2)
        {
            cnt += num2 & 1;
            num2 >>= 1;
        };

        vector<int> v;
        while (num1)
        {
            v.push_back(num1 & 1);
            num1 >>= 1;
        };

        for (int i = v.size() - 1; i >= 0; i--)
            if (v[i] && cnt)
            {
                v[i] = 2;
                cnt--;
            };
        for (int i = 0; i < v.size(); i++)
            if (!v[i] && cnt)
            {
                v[i] = 2;
                cnt--;
            };
        int ans = 0, tmp = 1;

        for (int i = 0; i < v.size(); i++)
        {
            if (v[i] == 2)
                ans += tmp;
            tmp <<= 1;
        };
        while (cnt--)
        {
            ans += tmp;
            tmp <<= 1;
        };
        return ans;
    }
};