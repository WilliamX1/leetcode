class Solution
{
  public:
    int findTheLongestSubstring(string s)
    {
        int n = s.size();
        vector<int> pos(1 << 5, -1);
        pos[0] = 0;

        int status = 0, ans = 0;

        for (int i = 0; i < n; i++)
        {
            switch (s[i])
            {
            case 'a':
                status ^= 1 << 0;
                break;
            case 'e':
                status ^= 1 << 1;
                break;
            case 'i':
                status ^= 1 << 2;
                break;
            case 'o':
                status ^= 1 << 3;
                break;
            case 'u':
                status ^= 1 << 4;
                break;
            };
            if (pos[status] == -1)
                pos[status] = i + 1;
            else
                ans = max(ans, i - pos[status] + 1);
        };
        return ans;
    }
};