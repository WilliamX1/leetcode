class Solution
{
  public:
    int percentageLetter(string s, char letter)
    {
        int count = 0, n = s.size();
        for (const char &ch : s)
            if (ch == letter)
                count++;
        return count * 100 / n;
    }
};