class Solution
{
  public:
    string reformat(string s)
    {
        string nums, alphas;
        for (const char &ch : s)
        {
            if ('0' <= ch && ch <= '9')
                nums.push_back(ch);
            else if ('a' <= ch && ch <= 'z' || 'A' <= ch && ch <= 'Z')
                alphas.push_back(ch);
            else
            {
                // impossible that
            };
        };
        int nsize = nums.size(), asize = alphas.size();
        if (abs(nsize - asize) > 1)
            return "";
        else if (nsize >= asize)
        {
            for (int i = 0; i < s.size(); i += 2)
                s[i] = nums[i / 2];
            for (int i = 1; i < s.size(); i += 2)
                s[i] = alphas[i / 2];
            return s;
        }
        else if (asize > nsize)
        {
            for (int i = 0; i < s.size(); i += 2)
                s[i] = alphas[i / 2];
            for (int i = 1; i < s.size(); i += 2)
                s[i] = nums[i / 2];
            return s;
        }
        else
            return "";
    }
};