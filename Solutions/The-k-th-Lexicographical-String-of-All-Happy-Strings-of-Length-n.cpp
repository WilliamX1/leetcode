class Solution
{
  public:
    vector<string> ans;
    void _getHappyString(string &str, const int &n, int k)
    {
        if (ans.size() >= k)
            return;

        if (str.size() == n)
        {
            ans.push_back(str);
            return;
        };

        for (char ch = 'a'; ch <= 'c'; ch++)
        {
            if (str.empty() || str.back() != ch)
            {
                str.push_back(ch);
                _getHappyString(str, n, k);
                str.pop_back();
            }
        };
        return;
    }
    string getHappyString(int n, int k)
    {
        string str = "";
        _getHappyString(str, n, k);
        return ans.size() >= k ? ans[k - 1] : "";
    }
};