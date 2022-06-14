class Solution
{
  public:
    int countCollisions(string directions)
    {
        int ans = 0;
        stack<char> stk;
        for (const char &ch : directions)
        {
            if (ch == 'L')
            {
                if (stk.empty() || stk.top() == 'L')
                    continue;
                else if (stk.top() == 'R')
                {
                    ans += 2;
                    stk.top() = 'S';
                }
                else if (stk.top() == 'S')
                {
                    ans += 1;
                };
            }
            else if (ch == 'R')
                stk.push(ch);
            else if (ch == 'S')
            {
                while (!stk.empty() && stk.top() == 'R')
                {
                    ans += 1;
                    stk.pop();
                };
                stk.push(ch);
            };
        };

        while (!stk.empty() && stk.top() == 'R')
            stk.pop();
        while (!stk.empty())
        {
            while (!stk.empty() && stk.top() == 'S')
                stk.pop();
            while (!stk.empty() && stk.top() == 'R')
            {
                ans += 1;
                stk.pop();
            };
        };
        return ans;
    }
};