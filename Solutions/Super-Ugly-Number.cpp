class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int m = primes.size(), idx = -1, max = 0x7fffffff;
        vector<int> ptr(m, 0), dp(n, 1);
        set<int> s;
        for (int i = 1; i < n; i++)
        {
            idx = -1, max = 0x7fffffff;
            for (int j = 0; j < m; j++)
            {
                int tmp = primes[j] * dp[ptr[j]];
                /* 去重 */
                while (s.find(tmp) != s.end()) {
                    ptr[j]++;
                    tmp = primes[j] * dp[ptr[j]];
                };
                if (tmp < max && s.find(tmp) == s.end()) {
                    max = tmp;
                    idx = j;
                };
            };
            ptr[idx]++;
            dp[i] = max;
            s.insert(dp[i]);
        };
        return dp[n - 1];
    };
};