class Solution
{
  public:
    int gcd(int x, int y)
    {
        int tmp;
        while (y >= 1)
        {
            tmp = x;
            x = y;
            y = tmp % y;
        };
        return x;
    };
    vector<int> fraction(vector<int> &cont)
    {
        int up = 0, down = 1;
        for (int i = cont.size() - 1; i >= 0; i--)
        {
            int next_up = down;
            int next_down = cont[i] * down + up;
            up = next_up;
            down = next_down;
        };
        int g = gcd(up, down);
        return {down / g, up / g};
    }
};