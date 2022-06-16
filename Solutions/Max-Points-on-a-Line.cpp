class Solution
{
  public:
    int maxPoints(vector<vector<int>> &points)
    {
        int n = points.size();
        int ans = 1;
        int tot = 0;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
            {
                tot = 2;
                for (int k = j + 1; k < n; k++)
                {
                    if ((points[k][1] - points[j][1]) * (points[j][0] - points[i][0]) ==
                        (points[j][1] - points[i][1]) * (points[k][0] - points[j][0]))
                        tot++;
                };
                ans = max(ans, tot);
            };
        return ans;
    }
};