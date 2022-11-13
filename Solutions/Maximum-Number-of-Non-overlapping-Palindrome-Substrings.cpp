class Solution
{
  public:
    bool OK(string s, int left, int right)
    {
        // cout << left << ' ' << right << endl;
        int i = 0;
        while (left + i < right - i)
        {
            if (s[left + i] != s[right - i])
                return false;
            else
                i++;
        };
        return true;
    };

    int maxPalindromes(string s, int k)
    {
        int n = s.size(), last = 0, ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (i - last + 1 >= k && OK(s, i - k + 1, i))
            {
                // cout << last << ' ' << i << endl;
                ans++;
                last = i + 1;
            }
            else if (i - last + 1 >= k + 1 && OK(s, i - k, i))
            {
                // cout << last << ' ' << i << endl;
                ans++;
                last = i + 1;
            };
        };
        return ans;
    }
};