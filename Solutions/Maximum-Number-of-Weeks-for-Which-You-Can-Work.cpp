class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        int64_t longest = -1, rest = 0;
        for (auto ele : milestones)
        {
            longest = longest > ele ? longest : ele;
            rest += ele;
        };
        rest -= longest;
        return longest > rest + 1 ? 2 * rest + 1: longest + rest;
    }
};