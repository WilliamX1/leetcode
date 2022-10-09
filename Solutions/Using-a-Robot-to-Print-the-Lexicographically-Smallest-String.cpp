class Solution
{
  public:
    string robotWithString(string s)
    {
        unordered_map<char, int> count;
        for (char &ch : s)
            count[ch]++;
        char cur_ch = 'a';
        while (cur_ch <= 'z' && !count[cur_ch])
            cur_ch++;

        string t, ans;
        int idx = 0, n = s.size();
        while (idx < n)
        {
            while (count[cur_ch])
            {
                while (idx < n && s[idx] != cur_ch)
                {
                    count[s[idx]]--;
                    t.push_back(s[idx++]);
                };
                count[cur_ch]--;
                ans.push_back(s[idx++]);
            };

            while (true)
            {
                char ch1 = t.empty() ? 'z' + 2 : t.back(), ch2 = 'z' + 1;
                for (char ch = 'a'; ch <= 'z'; ch++)
                    if (count[ch])
                    {
                        ch2 = ch;
                        break;
                    };
                if (ch1 <= ch2)
                {
                    ans.push_back(ch1);
                    t.pop_back();
                }
                else
                {
                    cur_ch = ch2;
                    break;
                };
            }
        };
        reverse(t.begin(), t.end());
        ans = ans + t;
        return ans;
    }
};