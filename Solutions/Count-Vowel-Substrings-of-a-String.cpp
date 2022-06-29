class Solution
{
  public:
    int countVowelSubstrings(string word)
    {
        int n = word.size(), ans = 0;
        for (int i = 0; i < n; i++)
        {
            vector<bool> v(5, false);
            for (int j = i; j < n; j++)
            {
                if (word[j] == 'a')
                    v[0] = true;
                else if (word[j] == 'e')
                    v[1] = true;
                else if (word[j] == 'i')
                    v[2] = true;
                else if (word[j] == 'o')
                    v[3] = true;
                else if (word[j] == 'u')
                    v[4] = true;
                else
                    break;
                if (accumulate(v.begin(), v.end(), 0) == 5)
                    ans++;
            };
        };
        return ans;
    }
};