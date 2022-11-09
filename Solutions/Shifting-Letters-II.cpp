class Solution
{
  public:
    string shiftingLetters(string s, vector<vector<int>> &shifts)
    {
        int n = s.size();
        vector<int> prefix(n + 1, 0);
        for (const vector<int> &v : shifts)
        {
            int start = v[0], end = v[1], dir = v[2];
            prefix[start] += dir == 1 ? 1 : -1;
            prefix[end + 1] -= dir == 1 ? 1 : -1;
        };
        prefix[0] %= 26;
        for (int i = 1; i <= n; i++)
            prefix[i] = (prefix[i] + prefix[i - 1]) % 26;

        for (int i = 0; i < n; i++)
        {
            if (s[i] + prefix[i] < 'a')
                s[i] += prefix[i] + 26;
            else if (s[i] + prefix[i] > 'z')
                s[i] += prefix[i] - 26;
            else
                s[i] += prefix[i];
        };
        return s;
    }
};