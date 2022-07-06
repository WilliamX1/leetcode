class Solution
{
  public:
    int numRookCaptures(vector<vector<char>> &board)
    {
        int x = 0, y = 0, m = board.size(), n = board[0].size(), ans = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (board[i][j] == 'R')
                {
                    x = i;
                    y = j;
                };

        const vector<vector<int>> position = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for (const vector<int> &pos : position)
        {
            int i = x + pos[0], j = y + pos[1];
            // cout << i << ' ' << j << endl;
            while (0 <= i && i < m && 0 <= j && j < n)
            {
                if (board[i][j] != '.')
                {
                    ans += board[i][j] == 'p';
                    break;
                };
                i += pos[0];
                j += pos[1];
            };
        };
        return ans;
    }
};