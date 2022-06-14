class Solution
{
  public:
    bool detectCapitalUse(string word)
    {
        bool flag = false;

        int i = 0;
        for (i = 0; i < word.size(); i++)
            if (word[i] < 'a' || word[i] > 'z')
                break;
        flag |= i == word.size();

        for (i = 0; i < word.size(); i++)
            if (word[i] < 'A' || word[i] > 'Z')
                break;
        flag |= i == word.size();

        if ('A' <= word[0] && word[0] <= 'Z')
        {
            for (i = 1; i < word.size(); i++)
                if (word[i] < 'a' || word[i] > 'z')
                    break;
            flag |= i == word.size();
        };

        return flag;
    }
};