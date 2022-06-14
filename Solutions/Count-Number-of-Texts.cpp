class Solution
{
  public:
    int countTexts(string pressedKeys)
    {
        int n = pressedKeys.size(), mod = 1e9 + 7;
        vector<int> dp(n, 0);
        dp[0] = 1;
        for (int i = 1; i < pressedKeys.size(); i++)
        {
            int last = i;
            while (last >= 0 && pressedKeys[i] == pressedKeys[last])
            {
                int same = i - last + 1;
                if (same > 3 && (pressedKeys[i] == '2' || pressedKeys[i] == '3' || pressedKeys[i] == '4' ||
                                 pressedKeys[i] == '5' || pressedKeys[i] == '6' || pressedKeys[i] == '8'))
                    break;
                else if (same > 4)
                    break;
                else
                {
                    dp[i] += last == 0 ? 1 : dp[last - 1];
                    dp[i] %= mod;
                    last--;
                };
            };
        };
        return dp[n - 1];
    }
};