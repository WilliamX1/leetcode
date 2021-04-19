#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int> arr;
        arr.push_back(nums.front());
        for (int i = 1; i < nums.size(); i++)
            arr.push_back(nums[i] ^ arr[i - 1]);
        
        vector<int> res;

        int mask = 1;
        for (int i = 1; i < maximumBit; i++)
            mask = (mask << 1) | 1;

        for (int i = 0; i < nums.size(); i++) {
            res.push_back((arr.back() ^ mask) & mask);
            arr.pop_back();
        };
        return res;
    }
};

int main()
{
    Solution S;
    vector<int> v = {0,1,1,3};

    S.getMaximumXor(v, 2);
    return 0;
}