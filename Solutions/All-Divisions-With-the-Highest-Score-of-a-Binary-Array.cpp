#include <vector>

using namespace std;

class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int len = nums.size();
        vector<int> zeros(len + 2, 0), ones(len + 2, 0);
        for (int i = 0; i < len; i++) {
            zeros[i + 1] = zeros[i] + (nums[i] == 0);
            ones[i + 1] = ones[i] + (nums[i] == 1);
        };
        zeros[len + 1] = zeros[len];
        ones[len + 1] = ones[len];

        int max_val = -1;
        vector<int> idxs;
        for (int i = 0; i <= len; i++) {
            int tot = zeros[i] + ones[len] - ones[i];
            if (tot > max_val) {
                max_val = tot;
                idxs.clear();
                idxs.push_back(i);
            } else if (tot == max_val) {
                idxs.push_back(i);
            } else {};
        };
        return idxs;
    }
};