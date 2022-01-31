class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos, neg;
        for (auto num : nums) {
            if (num > 0) pos.push_back(num);
            else neg.push_back(num);
        };
        vector<int> res;
        int len = pos.size();
        for (int i = 0; i < len; i++) {
            res.push_back(pos[i]);
            res.push_back(neg[i]);
        };
        return res;
    }
};