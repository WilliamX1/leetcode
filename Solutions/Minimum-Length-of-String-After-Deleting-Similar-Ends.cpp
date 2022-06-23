class Solution
{
  public:
    int minimumLength(string s)
    {
        int ans = s.size(), n = s.size(), left = 0, right = n - 1;
        while (left < right && s[left] == s[right])
        {
            char ch = s[left];
            while (left <= right && s[left] == ch)
                left++;
            while (left <= right && s[right] == ch)
                right--;
            if (ans > right - left + 1)
                ans = right - left + 1;
            else
                break;
        };
        return ans;
    }
};