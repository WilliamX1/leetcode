class Solution
{
  public:
    int maximumGroups(vector<int> &grades)
    {
        int n = grades.size();
        int ans = 1;
        while (true)
        {
            int tot = (1 + ans) * ans / 2;
            if (n < tot)
                break;
            else
                ans++;
        };
        return ans - 1;
    }
};