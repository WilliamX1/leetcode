class Solution
{
  public:
    int nextGreaterElement(int n)
    {
        int64_t nn = n;
        stack<int64_t> s;
        while (nn > 0)
        {
            int64_t b = nn % 10;
            nn /= 10;
            if (s.empty() || s.top() <= b)
                s.push(b);
            else
            {
                stack<int64_t> ss, sss;
                while (!s.empty() && s.top() > b)
                {
                    ss.push(s.top());
                    s.pop();
                };
                while (!s.empty())
                {
                    sss.push(s.top());
                    s.pop();
                }
                nn = nn * 10 + ss.top();
                ss.pop();
                while (!sss.empty())
                {
                    nn = nn * 10 + sss.top();
                    sss.pop();
                };
                nn = nn * 10 + b;
                while (!ss.empty())
                {
                    nn = nn * 10 + ss.top();
                    ss.pop();
                };
                break;
            };
        };
        if (nn <= 0 || nn > int64_t(INT32_MAX))
            return -1;
        else
            return nn;
    }
};