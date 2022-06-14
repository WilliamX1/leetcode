class Solution
{
  public:
    bool areOccurrencesEqual(string s)
    {
        vector<int> v(26, 0);
        int cnt = 0;
        for (const char &ch : s)
            cnt = ++v[ch - 'a'];
        for (const int &ele : v)
            if (ele > 0 && ele != cnt)
                return false;
        return true;
    }
};