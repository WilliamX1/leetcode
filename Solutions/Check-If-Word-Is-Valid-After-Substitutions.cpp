class Solution
{
  public:
    bool isValid(string s)
    {
        stack<char> stk;
        for (const char &ch : s)
        {
            if (stk.empty() || ch < 'c')
                stk.push(ch);
            else if (ch == 'c')
            {
                char ch1 = stk.top();
                stk.pop();
                if (stk.empty() || ch1 != 'b')
                    return false;
                char ch2 = stk.top();
                stk.pop();
                if (ch2 != 'a')
                    return false;
            }
            else
                stk.push(ch);
        };
        return stk.empty();
    }
};