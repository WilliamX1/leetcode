class Solution
{
  public:
    int minSwaps(vector<int> &chess)
    {
        int n = chess.size();
        vector<int> prefix(n, 0);
        prefix[0] = !chess[0];
        for (int i = 1; i < n; i++)
            prefix[i] = prefix[i - 1] + !chess[i];

        int ans = 1e6, cnt = n - prefix[n - 1];
        if (cnt == 0)
            return 0;
        else
        {
            // for (int i = 0; i < n; i++)
            //     cout << prefix[i] << ' ';

            for (int i = 0; i + cnt - 1 < n; i++)
                ans = min(ans, prefix[i + cnt - 1] - prefix[i] + !chess[i]);
            return ans;
        };
    }
};