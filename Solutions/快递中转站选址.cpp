class Solution
{
  public:
    int buildTransferStation(vector<vector<int>> &area)
    {
        int m = area.size(), n = area[0].size();

        int totx = 0, toty = 0, ansx = INT32_MAX, ansy = INT32_MAX;
        for (int x = 0; x < m; x++)
        {
            totx = 0;
            for (int i = 0; i < m; i++)
                for (int j = 0; j < n; j++)
                    if (area[i][j])
                        totx += abs(x - i);
            ansx = min(ansx, totx);
        };
        for (int y = 0; y < n; y++)
        {
            toty = 0;
            for (int i = 0; i < m; i++)
                for (int j = 0; j < n; j++)
                    if (area[i][j])
                        toty += abs(y - j);
            ansy = min(ansy, toty);
        };

        return ansx + ansy;
    }
};