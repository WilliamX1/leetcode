class Solution
{
  public:
    void _letterCasePermutation(string &s, int index, int n, vector<string> &ans)
    {
        if (index == n)
        {
            ans.push_back(s);
            return;
        }
        else
        {
            if ('a' <= s[index] && s[index] <= 'z')
            {
                s[index] = s[index] - 'a' + 'A';
                _letterCasePermutation(s, index + 1, n, ans);
                s[index] = s[index] - 'A' + 'a';
            };
            if ('A' <= s[index] && s[index] <= 'Z')
            {
                s[index] = s[index] - 'A' + 'a';
                _letterCasePermutation(s, index + 1, n, ans);
                s[index] = s[index] - 'a' + 'A';
            };
            _letterCasePermutation(s, index + 1, n, ans);
        };
    };
    vector<string> letterCasePermutation(string s)
    {
        vector<string> ans;
        _letterCasePermutation(s, 0, s.size(), ans);
        return ans;
    }
};