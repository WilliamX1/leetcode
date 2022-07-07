class Solution
{
  public:
    string reversePrefix(string word, char ch)
    {
        int i = 0, n = word.size();
        while (i < n && word[i] != ch)
            i++;

        if (i < n)
        {
            string ans;
            for (int j = i; j >= 0; j--)
                ans.push_back(word[j]);
            for (int j = i + 1; j < n; j++)
                ans.push_back(word[j]);
            return ans;
        }
        else
            return word;
    }
};