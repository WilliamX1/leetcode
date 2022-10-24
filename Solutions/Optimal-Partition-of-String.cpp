class Solution
{
  public:
    int partitionString(string s)
    {
        set<int> count;
        int ans = 0;
        for (const char &ch : s)
        {
            if (count.count(ch))
            {
                ans++;
                count.clear();
                count.insert(ch);
            }
            else
                count.insert(ch);
        };
        ans += !!count.size();
        return ans;
    }
};