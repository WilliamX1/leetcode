class Solution
{
  public:
    bool splitString(string s)
    {
        int64_t n = s.size();
        for (int64_t len = 1; len < n; len++)
        {
            int64_t num = 0, j = 0;
            while (j < len && s[j] == '0')
                j++;
            while (j < len && num < 1e15)
                num = 10 * num + (s[j++] - '0');

            bool flag = true, cnt = false;
            while (j < n)
            {
                int64_t next_num = 0;
                while (j < n && s[j] == '0')
                    j++;
                while (j < n && next_num < num - 1)
                    next_num = 10 * next_num + (s[j++] - '0');
                if (next_num != num - 1)
                {
                    flag = false;
                    break;
                }
                else
                {
                    // cout << num << endl;
                    cnt = true;
                    num = next_num;
                };
            };
            if (flag && cnt)
                return true;
        };
        return false;
    }
};