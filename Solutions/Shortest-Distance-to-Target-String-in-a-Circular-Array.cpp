class Solution
{
  public:
    int closetTarget(vector<string> &words, string target, int startIndex)
    {
        int ans1 = 0, n = words.size(), ori_startindex = startIndex;
        while (ans1 < n)
        {
            if (words[startIndex] == target)
                break;
            else
            {
                ans1++;
                startIndex = (startIndex + 1) % n;
            };
        };

        int ans2 = 0;
        startIndex = ori_startindex;
        while (ans2 < n)
        {
            if (words[startIndex] == target)
                break;
            else
            {
                ans2++;
                startIndex = (startIndex - 1 + n) % n;
            };
        }
        // cout << ans1 << ' ' << ans2 << endl;
        return ans1 == n && ans2 == n ? -1 : min(ans1, ans2);
    }
};