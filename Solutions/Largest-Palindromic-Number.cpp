class Solution
{
  public:
    string largestPalindromic(string num)
    {
        unordered_map<char, int> count;
        for (const char &ch : num)
            count[ch]++;
        string prefix;
        for (char ch = '9'; ch >= '0'; ch--)
        {
            if (ch >= '1' || ch == '0' && !prefix.empty())
                while (count[ch] >= 2)
                {
                    prefix.push_back(ch);
                    count[ch] -= 2;
                };
        };
        char mid = ' ';
        for (char ch = '9'; ch >= '0'; ch--)
        {
            if (count[ch])
            {
                mid = ch;
                break;
            };
        };
        string postfix = prefix;
        reverse(postfix.begin(), postfix.end());

        if (mid != ' ')
            prefix.push_back(mid);
        return prefix + postfix;
    }
};