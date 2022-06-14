class Solution
{
  public:
    bool isPalindrome(string s)
    {
        string str = "";
        for (const char ch : s)
        {
            if ('A' <= ch && ch <= 'Z')
                str.push_back(ch - 'A' + 'a');
            else if ('a' <= ch && ch <= 'z' || '0' <= ch && ch <= '9')
                str.push_back(ch);
            else
            {
            };
        };
        string rev_str = str;
        reverse(rev_str.begin(), rev_str.end());
        return str == rev_str;
    }
};