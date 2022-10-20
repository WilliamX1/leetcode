class Solution
{
  public:
    long long minimumMoney(vector<vector<int>> &transactions)
    {
        long long tot_lose = 0;
        for (const vector<int> &t : transactions)
            tot_lose += max(t[0] - t[1], 0);
        long long ans = 0;
        for (const vector<int> &t : transactions)
            if (t[0] <= t[1])
                ans = max(ans, tot_lose + t[0]);
            else
                ans = max(ans, tot_lose + t[1]);
        return ans;
    }
};