class Solution
{
  public:
    pair<int, int> findPos(const vector<string> &v, const char &ch)
    {
        for (int i = 0; i < v.size(); i++)
        {
            for (int j = 0; j < v[i].size(); j++)
            {
                if (v[i][j] == ch)
                {
                    return make_pair(i, j);
                };
            };
        };
        return make_pair(-1, -1);
    }
    string alphabetBoardPath(string target)
    {
        vector<string> v = {"abcde", "fghij", "klmno", "pqrst", "uvwxy", "z"};
        string ans;

        pair<int, int> lastPos = {0, 0};
        for (const char &ch : target)
        {
            pair<int, int> curPos = findPos(v, ch);
            int upDown = curPos.first - lastPos.first, leftRight = curPos.second - lastPos.second;
            if (v[curPos.first][curPos.second] == 'z')
            {
                ans.append(leftRight >= 0 ? string(leftRight, 'R') : string(-leftRight, 'L'));
                ans.append(upDown >= 0 ? string(upDown, 'D') : string(-upDown, 'U'));
            }
            else
            {
                ans.append(upDown >= 0 ? string(upDown, 'D') : string(-upDown, 'U'));
                ans.append(leftRight >= 0 ? string(leftRight, 'R') : string(-leftRight, 'L'));
            };
            ans.push_back('!');
            lastPos = curPos;
        };
        return ans;
    }
};