class Solution
{
  public:
    int gcd(int a, int b)
    {
        while (a > 0)
        {
            b %= a;
            swap(a, b);
        };
        return b;
    };
    vector<int> replaceNonCoprimes(vector<int> &nums)
    {
        stack<int> s;
        s.push(nums[0]);
        for (int i = 1; i < nums.size(); i++)
        {
            s.push(nums[i]);
            while (s.size() > 1)
            {
                int x = s.top();
                s.pop();
                int y = s.top();
                s.pop();
                int g = gcd(x, y);
                if (g == 1)
                {
                    s.push(y);
                    s.push(x);
                    break;
                }
                else
                {
                    s.push((x / g) * (y / g) * g);
                };
            };
        };
        vector<int> v;
        while (!s.empty())
        {
            v.push_back(s.top());
            s.pop();
        };
        reverse(v.begin(), v.end());
        return v;
    }
};