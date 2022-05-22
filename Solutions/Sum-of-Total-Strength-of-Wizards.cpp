class Solution {
public:
    int totalStrength(vector<int>& strength) {
        strength.insert(strength.begin(), 0);
        strength.insert(strength.end(), 0);

        int n = strength.size();
        int ans = 0, mod = 1e9 + 7, sum = 0;
        vector<long long> prefix(n), tot_prefix(n), suffix(n), tot_suffix(n);
        prefix[0] = strength[0];
        tot_prefix[0] = strength[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + (int64_t) strength[i];
            tot_prefix[i] = tot_prefix[i - 1] + (int64_t) (i + 1) * (int64_t) strength[i];
        };

        suffix[n - 1] = strength[n - 1];
        tot_suffix[n - 1] = strength[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + (int64_t) strength[i];
            tot_suffix[i] = tot_suffix[i - 1] + (int64_t) (n - i) * (int64_t) strength[i];
        };

        map<int, int> pre_m, suf_m;
        pre_m[0] = 0;
        for (int i = 1; i < n - 1; i++) {
            auto iter = pre_m.upper_bound(strength[i]);
            --iter;

            int pre_idx = iter->second;

            ans += (tot_prefix[i - 1] - tot_prefix[pre_idx] - (pre_idx + 1) * (prefix[pre_idx] - prefix[i - 1])) * (suf_idx - i);
        }
        
        return ans;
    }
};