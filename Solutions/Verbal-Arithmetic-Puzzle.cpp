class Solution
{
  public:
    bool dfs(const vector<vector<char>> &charsets, const string &result, const int &m, const int x, const int y, int p,
             vector<int> &v, vector<bool> &haveused, const vector<char> &pre)
    {
        if (y == charsets[x].size())
        {
            int tot = p;
            for (const char &ch : charsets[x])
                tot += v[ch - 'A'];
            p = tot / 10;
            int more = tot % 10;
            bool ans = false;
            if (v[result[x] - 'A'] < 0 && !haveused[more] || v[result[x] - 'A'] == more)
            {
                int flag1 = v[result[x] - 'A'], flag2 = haveused[more];
                v[result[x] - 'A'] = more;
                haveused[more] = true;
                if (x == charsets.size() - 1)
                {
                    if (result.size() > m)
                        ans = ((v[result.back() - 'A'] < 0 && !haveused[p]) || v[result.back() - 'A'] == p) &&
                              p; // && !p;
                    else
                        ans = p == 0;
                    // 检查前导 0
                    for (const char &ch : pre)
                        if (!v[ch - 'A'])
                            ans = false;
                }
                else
                    ans = dfs(charsets, result, m, x + 1, 0, p, v, haveused, pre);

                if (ans)
                    return true;

                v[result[x] - 'A'] = flag1;
                haveused[more] = flag2;
                return ans;
            }
            else
                return false;
        };
        if (v[charsets[x][y] - 'A'] == -1)
        {
            for (int i = 0; i <= 9; i++)
            {
                if (!haveused[i])
                {
                    v[charsets[x][y] - 'A'] = i;
                    haveused[i] = true;
                    if (dfs(charsets, result, m, x, y + 1, p, v, haveused, pre))
                        return true;
                    haveused[i] = false;
                    v[charsets[x][y] - 'A'] = -1;
                }
            };
            return false;
        }
        else
            return dfs(charsets, result, m, x, y + 1, p, v, haveused, pre);
    };
    bool isSolvable(vector<string> &words, string result)
    {
        reverse(result.begin(), result.end());
        vector<char> pre;
        int n = words.size(), m = 0;
        for (const string &w : words)
        {
            m = max(m, (int)w.size());
            if (w.size() > 1)
                pre.push_back(w.front());
        };
        if (result.size() - m > 1)
            return false;
        vector<vector<char>> charsets(m);
        for (const string &w : words)
            for (int i = 0; i < w.size(); i++)
                charsets[w.size() - i - 1].push_back(w[i]);
        vector<int> v(26, -1);
        vector<bool> haveused(10, false);
        bool ans = dfs(charsets, result, m, 0, 0, 0, v, haveused, pre);
        for (int i = 0; i < 26; i++)
            cout << ' ' << char('A' + i) << ' ' << v[i];
        cout << endl;
        return ans;
    }
};