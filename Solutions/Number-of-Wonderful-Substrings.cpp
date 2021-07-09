class Solution {
public:
    bool judge(int64_t num) {
        int64_t ans = 0;
        for (int64_t i = 0; i < 10; i++)
        {
            ans += num & 1;
            num >>= 1;
        };
        return ans <= 1;
    };
    long long wonderfulSubstrings(string word) {
        int64_t len = word.size(), step = 0, ans = 0;
        vector<int64_t> dp(len, 0); dp[0] = 1 << (word[0] - 'a');
        for (int64_t i = 1; i < len; i++)
            dp[i] = dp[i - 1] ^ (1 << (word[i] - 'a'));
        unordered_map<int64_t, int64_t> m;
        for (int64_t i = 0; i < len; i++)
        {
            ans += judge(dp[i]);
            
            auto iter = m.find(dp[i]);
            
            if (iter != m.end())
                ans += iter->second;
            for (int64_t j = 0; j < 10; j++) {
                int64_t mask = dp[i] ^ (1 << j);
                if (m.find(mask) != m.end()) ans += m.find(mask)->second;
            };
        
            if (iter != m.end()) iter->second++;
            else m.insert(make_pair(dp[i], 1));
        };
        return ans;
    }
};