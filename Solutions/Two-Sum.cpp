#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> _map;
        for (int i = 0; i < nums.size(); i++)
        {
            auto iter = _map.find(target - nums[i]);
            if (iter != _map.end()) return {iter->second, i};
            else _map[nums[i]] = i;
        }
        return {};
    }
};

int main()
{
    Solution S;
    vector<int> arr = {1, 2, 4, -5, -2};
    printf("%d %d", S.twoSum(arr, 0)[0], S.twoSum(arr, 0)[1]);

    return 0;
}