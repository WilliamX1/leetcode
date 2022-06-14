class Solution
{
  public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>> &queries)
    {
        int n = s.size();
        vector<int> star_forward(n), star_backward(n), line(n);
        star_forward[n - 1] = s[0] == '*';
        star_backward[0] = s[0] == '*';
        line[0] = s[0] == '|';
        for (int i = n - 2; i >= 0; i--)
            star_forward[i] = s[i] == '*' ? 1 + star_forward[i + 1] : 0;
        for (int i = 1; i < n; i++)
            star_backward[i] = s[i] == '*' ? 1 + star_backward[i - 1] : 0;
        for (int i = 1; i < n; i++)
            line[i] = line[i - 1] + (s[i] == '|');

        int m = queries.size(), left, right;
        vector<int> answer(m);
        for (int i = 0; i < m; i++)
        {
            left = queries[i][0], right = queries[i][1];
            // cout << right << ' ' << left << ' ' << star_backward[right] << ' ' << star_forward[left] << ' ' <<
            // line[right] << ' ' << line[left - 1] << endl;
            int line_cnt = line[right] - (left ? line[left - 1] : 0);
            if (line_cnt >= 2)
                answer[i] = (right - left + 1) - star_backward[right] - star_forward[left] -
                            (line[right] - (left ? line[left - 1] : 0));
            else
                answer[i] = 0;
        };

        return answer;
    }
};