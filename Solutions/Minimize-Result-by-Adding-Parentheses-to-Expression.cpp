class Solution
{
  public:
    string minimizeResult(string expression)
    {
        int plus_idx = expression.find('+'), ans = 0x7fffffff;
        string res;
        for (int i = 0; i < plus_idx; i++)
        {
            for (int j = plus_idx + 1; j < expression.length(); j++)
            {
                int prev_mul = i == 0 ? 1 : stol(expression.substr(0, i));
                int prev_add = stol(expression.substr(i, plus_idx - i));
                int post_add = stol(expression.substr(plus_idx + 1, j - plus_idx));
                int post_mul = j == expression.length() - 1 ? 1 : stol(expression.substr(j + 1));
                int tmp = prev_mul * (prev_add + post_add) * post_mul;
                if (tmp < ans)
                {
                    ans = tmp;
                    res = expression.substr(0, i) + "(" + expression.substr(i, j - i + 1) + ")" +
                          expression.substr(j + 1);
                };
            };
        };
        // cout << ans;
        return res;
    }
};