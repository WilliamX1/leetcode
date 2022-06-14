class Solution
{
  public:
    vector<int> executeInstructions(int n, vector<int> &startPos, string s)
    {
        int m = s.size();
        vector<int> answer(m, 0);
        for (int i = 0; i < m; i++)
        {
            int x = startPos[0], y = startPos[1];

            for (int j = i; j < m; j++)
            {
                switch (s[j])
                {
                case 'L':
                    y--;
                    break;
                case 'R':
                    y++;
                    break;
                case 'U':
                    x--;
                    break;
                case 'D':
                    x++;
                    break;
                };
                if (0 <= x && x < n && 0 <= y && y < n)
                    answer[i]++;
                else
                    break;
            };
        };
        return answer;
    }
};