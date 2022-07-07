class Solution
{
  public:
    int gcd(int x, int y)
    {
        int tmp;
        while (x)
        {
            tmp = x;
            x = y % x;
            y = tmp;
        };
        return y;
    };

    long long interchangeableRectangles(vector<vector<int>> &rectangles)
    {
        map<pair<int, int>, int> m;
        for (const vector<int> &v : rectangles)
        {
            int width = v[0], height = v[1], g = gcd(width, height);
            m[make_pair(width / g, height / g)]++;
        };
        long long ans = 0;
        for (const auto &iter : m)
        {
            long long val = iter.second;
            ans += val * (val - 1) / 2;
        };
        return ans;
    }
};