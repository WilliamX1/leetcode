class Solution
{
  public:
    long long makeIntegerBeautiful(long long n, int target)
    {
        string str = to_string(n);

        str.insert(str.begin(), '0');
        for (int i = 0; i < str.size(); i++)
        {
            int tmp_cnt = 0;
            for (int j = i + 1; j < str.size(); j++)
                tmp_cnt += str[j] - '0';
            if (i < str.size() - 1)
                tmp_cnt = min(tmp_cnt, str[i + 1] - '0' + 1);
            if (tmp_cnt + str[i] - '0' > target)
            {
                for (int j = i; j >= 0; j--)
                    if (str[j] != '9')
                    {
                        str[j]++;
                        break;
                    }
                    else
                        str[j] = '0';
                for (int j = i + 1; j < str.size(); j++)
                    str[j] = '0';
                return stoll(str) - n;
            }
            else
                target -= str[i] - '0';
        };
        return stoll(str) - n;
    }
};