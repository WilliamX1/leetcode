#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  public:
    int minDays(vector<int> &bloomDay, int m, int k)
    {
        int low = 0, high = *max_element(bloomDay.begin(), bloomDay.end()), mid;
        while (low < high)
        {
            mid = (low + high) >> 1;
            if (canMake(bloomDay, mid, m, k))
                high = mid;
            else
                low = mid + 1;
        };
        return canMake(bloomDay, low, m, k) ? low : -1;
    };
    bool canMake(vector<int> &bloomDay, int mid, int m, int k)
    {
        int ans = 0;
        int sum = 0;
        for (int i = 0; i < bloomDay.size(); i++)
        {
            if (bloomDay[i] > mid)
                sum = 0;
            else if (++sum == k)
                ans++, sum = 0;

            if (ans >= m)
                return true;
        };
        return false;
    }
};

int main()
{
    Solution S;
    vector<int> v = {1, 10, 3, 10, 2};
    cout << S.minDays(v, 3, 2);
    return 0;
}