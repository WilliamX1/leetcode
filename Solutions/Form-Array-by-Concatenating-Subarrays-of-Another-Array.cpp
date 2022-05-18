class Solution {
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        int n = nums.size(), idx = 0;
        for (vector<int>& group : groups) {
            int start = group.front();

            do {
                bool flag = false;

                while (idx < n && nums[idx] != start) idx++;
                if (idx == n) return false;
                else {
                    int tmp = idx;
                    for (int i = 1; i < group.size(); i++) {
                        if (tmp + i >= n || nums[tmp + i] != group[i]) {
                            flag = true;
                            break;
                        };
                    };
                    if (flag) {
                        idx += 1;
                        continue;
                    } else {
                        idx += group.size();
                        break;
                    };
                };
            } while (true);
        };
        return true;
    }
};