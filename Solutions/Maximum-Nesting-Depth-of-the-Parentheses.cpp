class Solution
{
  public:
    int maxDepth(string s)
    {
        stack<char> stk;
        int ans = 0;
        for (const char &ch : s)
        {
            if (ch == '(')
            {
                stk.push(ch);
                ans = max(ans, (int)stk.size());
            }
            else if (ch == ')')
            {
                stk.pop();
            }
            else
            {
            };
        };
        return ans;
    }
};