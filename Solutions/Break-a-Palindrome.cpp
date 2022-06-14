class Solution
{
  public:
    string breakPalindrome(string palindrome)
    {
        int len = palindrome.size();
        if (len == 1)
            return "";
        else
        {
            for (char ch = 'a'; ch <= 'z'; ch++)
                for (int i = 0; i < len; i++)
                {
                    if ((len & 1) && i == len / 2)
                        continue;
                    if (palindrome[i] > ch)
                    {
                        palindrome[i] = ch;
                        return palindrome;
                    };
                };

            palindrome[len - 1] = 'b';
            return palindrome;
        };
        return "";
    }
};