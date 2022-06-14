#include <algorithm>
#include <cmath>

using namespace std;

class Solution
{
  public:
    int countElements(vector<int> &nums)
    {
        int m = 0x7fffffff, M = 0x80000000;
        for (auto num : nums)
        {
            m = min(m, num);
            M = max(M, num);
        };
        int cnt = 0;
        for (auto num : nums)
            cnt += m < num && num < M;
        return cnt;
    }
};