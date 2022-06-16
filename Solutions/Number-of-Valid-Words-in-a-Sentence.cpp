class Solution
{
  public:
    bool judge(const string &str)
    {
        if (str.empty())
            return false;

        int idx1 = -1, flag = false;
        for (int i = 0; i < str.size(); i++)
        {
            char ch = str[i];
            if ('a' <= ch && ch <= 'z')
                flag = true;
            if (ch == '-')
            {
                if (idx1 < 0)
                {
                    idx1 = i;
                    if (flag == false)
                        return false;
                    else
                        flag = false;
                }
                else
                    return false;
            };
            if ((ch == '!' || ch == '.' || ch == ',') && i != str.size() - 1)
                return false;
            if ('a' <= ch && ch <= 'z' || ch == '-' || ch == '!' || ch == '.' || ch == ',')
                continue;
            else
                return false;
        };
        return idx1 < 0 || flag;
    }
    int countValidWords(string sentence)
    {
        int ans = 0;
        string tmp;
        for (int i = 0; i < sentence.size(); i++)
        {
            if (sentence[i] == ' ')
            {
                ans += judge(tmp);
                tmp.clear();
            }
            else
                tmp += sentence[i];
        };
        ans += judge(tmp);
        return ans;
    }
};