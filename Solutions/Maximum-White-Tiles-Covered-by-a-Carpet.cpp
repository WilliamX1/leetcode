class Solution
{
  public:
    int maximumWhiteTiles(vector<vector<int>> &tiles, int carpetLen)
    {
        sort(tiles.begin(), tiles.end(), [](const vector<int> &a, const vector<int> &b) { return a[0] < b[0]; });

        int n = tiles.size();
        vector<int> sum(n);
        sum[0] = (int)tiles[0][1] - (int)tiles[0][0] + 1;
        for (int i = 1; i < n; ++i)
            sum[i] = sum[i - 1] + (int)tiles[i][1] - (int)tiles[i][0] + 1;

        vector<int> leftpos(n);
        for (int i = 0; i < n; ++i)
            leftpos[i] = (int)tiles[i][0];
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int left = (int)tiles[i][0], right = left + (int)carpetLen - 1;
            int rightidx = upper_bound(leftpos.begin(), leftpos.end(), right) - leftpos.begin();
            ans = max(ans, sum[rightidx - 1] - (i == 0 ? 0 : sum[i - 1]) - max(0, tiles[rightidx - 1][1] - right));
        };
        return ans;
    }
};