class Solution
{
  public:
    int takeCharacters(string s, int k)
    {
        int n = s.size();
        vector<int> presumA(n, 0), presumB(n, 0), presumC(n, 0);
        presumA[0] = s[0] == 'a';
        presumB[0] = s[0] == 'b';
        presumC[0] = s[0] == 'c';

        for (int i = 1; i < n; i++)
        {
            presumA[i] = presumA[i - 1] + (s[i] == 'a');
            presumB[i] = presumB[i - 1] + (s[i] == 'b');
            presumC[i] = presumC[i - 1] + (s[i] == 'c');
        };

        if (k == 0)
            return 0;
        if (presumA.back() < k || presumB.back() < k || presumC.back() < k)
            return -1;

        int ans = 1e9 + 7, targetA = k, targetB = k, targetC = k;

        for (int right = 0; right < n; right++)
        {
            int idxA = targetA > 0 ? lower_bound(presumA.begin(), presumA.end(), targetA) - presumA.begin() : -1;
            int idxB = targetB > 0 ? lower_bound(presumB.begin(), presumB.end(), targetB) - presumB.begin() : -1;
            int idxC = targetC > 0 ? lower_bound(presumC.begin(), presumC.end(), targetC) - presumC.begin() : -1;
            ans = min(ans, max(idxA + 1, max(idxB + 1, idxC + 1)) + right);

            targetA -= s[n - 1 - right] == 'a';
            targetB -= s[n - 1 - right] == 'b';
            targetC -= s[n - 1 - right] == 'c';
        };
        return ans == 1e9 + 7 ? -1 : ans;
    }
};