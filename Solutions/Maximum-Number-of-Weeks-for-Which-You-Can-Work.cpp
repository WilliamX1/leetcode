class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        int64_t longest = -1, rest = 0;
        for (auto ele : milestones)
        {
            longest = max(longest, ele);
            rest += ele;
        }
    }
};