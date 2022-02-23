#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for (const int& num : nums)
            s.insert(num);

        int ans = 0;
        for (const int& num : nums) {
            if (!s.count(num - 1)) {
                int tot = 0;
                int i = num;
                while (s.count(i)) {
                    tot++;
                    i++;
                };
                ans = max(ans, tot);
            };
        };
        return ans;
    };
};