class Solution
{
  public:
    int findNthDigit(int n)
    {
        vector<vector<int64_t>> v = {
            {0, 0},          {10, 10},          {90, 180},           {900, 2700},           {9000, 36000},
            {90000, 450000}, {900000, 5400000}, {9000000, 63000000}, {90000000, 720000000}, {900000000, 8100000000}};
        for (int i = 1; i < v.size(); i++)
        {
            v[i][1] += v[i - 1][1];
        };
        int idx = -1;
        for (int i = 1; i < v.size(); i++)
        {
            if (v[i][1] <= n)
                continue;
            else
            {
                idx = i - 1;
                break;
            };
        };
        int64_t nn = n;
        nn += 1;
        int num = (idx == 0 ? 0 : pow(10, idx)) + (nn - v[idx][1] - 1) / (idx + 1),
            rem = (nn - v[idx][1] - 1) % (idx + 1);
        return to_string(num)[rem] - '0';
    }
};