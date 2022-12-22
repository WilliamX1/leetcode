class Solution
{
  public:
    int maximumValue(vector<string> &strs)
    {
        int n = strs.size();
        vector<int> ans;
        for (string &str : strs)
        {
            int num = 0;
            for (char &ch : str)
            {
                if ('0' <= ch && ch <= '9')
                    num = num * 10 + (ch - '0');
                else
                {
                    num = str.size();
                    break;
                };
            };
            ans.push_back(num);
        };
        return *max_element(ans.begin(), ans.end());
    }
};