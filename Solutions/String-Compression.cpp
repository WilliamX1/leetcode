class Solution
{
  public:
    int compress(vector<char> &chars)
    {
        int len = chars.size(), idx = 0, last_idx = 0;
        while (idx < len)
        {
            char cur = chars[idx];
            int cur_len = 0;
            cout << "cur: " << cur << endl;
            while (idx < len && chars[idx] == cur)
            {
                idx++;
                cur_len++;
            };

            string str = cur_len > 1 ? to_string(cur_len) : "";

            chars[last_idx++] = cur;
            for (const char &ch : str)
            {
                cout << last_idx << ' ';
                chars[last_idx++] = ch;
            };
        };
        return last_idx;
    }
};