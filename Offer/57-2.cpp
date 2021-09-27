class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        int64_t len = target >> 1, tmp, x, assert;
        vector<vector<int>> ans;
        for (int i = 1; i <= len; i++) {
            /* (start + start + len - 1) * len / 2 = target */
            /* x^2 + (2i - 1) * x - 2t = 0; */
            /* x = ((1 - 2i) + sqrt((2i - 1)^2 + 8t)) / 2*/
            tmp = 1 - (i << 1);
            x = int64_t(sqrt(tmp * tmp + (target << 3)) + tmp) >> 1;
            assert = (((-tmp + x) * x) >> 1) == target;
            if (assert) {
                std::vector<int> v(x);
                std::iota(v.begin(), v.end(), i);
                ans.push_back(v);
            }
        };
        return ans;
    }
};