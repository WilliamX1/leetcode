#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        /*简单移除每一个重复元素*/
        // if (!nums.empty()) {
        //     int prev = nums.front();
        //     auto cursor = ++nums.begin();
        //     while (cursor != nums.end()) {
        //         if (*cursor == prev) nums.erase(cursor);
        //         else prev = *cursor++;
        //     };
        // };
        // return nums.size();
        /*利用集合*/
        // set<int> s;
        // int _size = nums.size();
        // for (int i = 0; i < _size; i++)
        //     s.insert(nums[i]);
        // auto cursor = s.begin();
        // nums.clear();
        // _size = s.size();
        // for (int i = 0; i < _size; i++)
        // {
        //     nums.push_back(*cursor);
        //     cursor++;
        // };
        // return _size;
        /*批量删除同一个值*/
        // if (!nums.empty()) {
        //     int prev = nums.front(), left;
        //     auto cursor = ++nums.begin();
        //     while (cursor != nums.end()) {
        //         if (*cursor != prev) prev = *cursor, cursor++;
        //         else nums.erase(cursor, upper_bound(cursor, nums.end(), *cursor));
        //     }
        // };
        // return nums.size();
        /*双指针*/
        int _size = nums.size();
        if (_size == 0) return 0;
        else {
            int fast = 1, slow = 1;
            while (fast < _size) {
                if (nums[fast] != nums[fast - 1]) {
                    nums[slow] = nums[fast];
                    ++slow;
                }
                ++fast;
            };
            return slow;
        }
    }
};

int main()
{
    Solution S;
    vector<int> v = {1, 2};
    int len = S.removeDuplicates(v);

    return 0;
}