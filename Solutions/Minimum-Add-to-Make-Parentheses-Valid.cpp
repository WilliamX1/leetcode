class Solution
{
  public:
    int minAddToMakeValid(string s)
    {
        stack<char> stk;
        int ans = 0;
        for (const char &ch : s)
        {
            if (ch == '(')
                stk.push(ch);
            else if (ch == ')')
            {
                if (stk.empty())
                    ans++;
                else
                    stk.pop();
            }
            else
            {
                // impossible
            };
        };
        ans += stk.size();
        return ans;
    }
};