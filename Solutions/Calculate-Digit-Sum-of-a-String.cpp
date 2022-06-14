class Solution
{
  public:
    string digitSum(string s, int k)
    {
        while (s.size() > k)
        {
            string ss;
            int index = 0, n = s.size();
            while (index < n)
            {
                int tot = 0, cnt = 0;
                while (index < n && cnt++ < k)
                    tot += s[index++] - '0';
                ss.append(to_string(tot));
            };
            s = ss;
        };
        return s;
    }
};