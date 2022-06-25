class Solution
{
  public:
    int largestAltitude(vector<int> &gain)
    {
        int ans = 0, tot = 0;
        for (const int &g : gain)
        {
            tot += g;
            ans = max(ans, tot);
        };
        return ans;
    }
};