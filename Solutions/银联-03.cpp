class Solution {
public:
    int maxInvestment(vector<int>& product, int limit) {
        int64_t ans = 0, mod = 1e9 + 7, left = 0, right = 1e7 + 1;

        int64_t acc = 0;
        for (int& pro : product)
            acc = (acc + (int64_t) pro);
        if (acc <= limit) {
            int64_t ans = 0;
            for (int& pro : product) {
                ans = (ans + (int64_t) pro * ((int64_t) pro + 1) / 2) % mod;
            };
            return ans;
        }

        while (left < right) {
            int mid = (left + right) >> 1;
            int64_t tot = 0;
            for (int& pro : product)
                if (pro >= mid) 
                    tot += (int64_t) pro - (int64_t) mid;
            if (tot >= (int64_t) limit) left = mid + 1;
            else right = mid - 1;
        };
        left = left + 1;

        for (int& pro : product) {
            if (pro >= left) {
                ans = (ans + ((int64_t) pro + (left + 1)) * ((int64_t) pro - left) / 2) % mod;
                limit -= pro - left;
            };
        };
        while (limit > 0) {
            for (int& pro : product) {
                if (pro >= left) {
                    ans = (ans + left) % mod;
                    limit--;
                };
                if (limit == 0) break;
            };
            left--;
        };
        return ans;
    }
};