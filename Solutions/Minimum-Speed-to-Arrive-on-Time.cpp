#include <bits/stdc++.h>

using namespace std;

class Solution
{
  public:
    bool canGet(const vector<int> &dist, const double hour, int speed)
    {
        int ans = 0;
        for (auto dis : dist)
        {
            ans += dis / speed;
            if (dis % speed != 0)
                ans++;
        };
        return hour >= ans;
    }
    int minSpeedOnTime(vector<int> &dist, double hour)
    {
        /* 二分查找车速 */
        int last = dist.back();
        dist.pop_back();

        sort(dist.begin(), dist.end());

        int left = 1, right = 100000000, mid;
        if (!canGet(dist, hour - double(last) / double(right), right))
            return -1;
        while (left <= right)
        {
            mid = (left + right) >> 1;
            if (canGet(dist, hour - double(last) / double(mid), mid))
                right = mid - 1;
            else
                left = mid + 1;
        };
        return left - 1;
    }
};

int main()
{
    vector<int> v = {1, 3, 2};
    Solution S;
    cout << S.minSpeedOnTime(v, 6);
    return 0;
}