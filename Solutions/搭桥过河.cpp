class Solution
{
  public:
    long long buildBridge(int num, vector<vector<int>> &wood)
    {
        int n = wood.size(), left = wood[0][0], right = wood[0][1], ans = 0;
        for (int i = 1; i < n; i++)
        {
            int step;
            if (wood[i][0] > right)
            {
                step = wood[i][0] - right;
                ans += step;
                left = right;
                right = wood[i][1];
            }
            else if (wood[i][1] < left)
            {
                step = left - wood[i][1];
                ans += step;
                right = left;
                left = wood[i][0];
            }
            else
            {
                left = wood[i][0];
                right = wood[i][1];
            };
        };
        return ans;
    }
};