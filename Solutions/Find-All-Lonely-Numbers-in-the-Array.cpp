#include <unordered_map>

using namespace std;

class Solution
{
  public:
    vector<int> findLonely(vector<int> &nums)
    {
        unordered_map<int, int> m;
        for (auto num : nums)
            m[num]++;
        vector<int> v;
        for (auto num : nums)
            if (m[num] == 1 && !m.count(num - 1) && !m.count(num + 1))
                v.push_back(num);
        return v;
    }
};