#include <bits/stdc++.h>

using namespace std;

class Solution
{
  public:
    int maxArea(vector<int> &height)
    {
        int m = height.size();
        int left = 0, right = m - 1, ans = 0;
        while (left < right)
        {
            if (height[left] < height[right])
            {
                ans = max(ans, (right - left) * height[left]);
                left++;
            }
            else
            {
                ans = max(ans, (right - left) * height[right]);
                right--;
            };
        }
        return ans;
    }
};

int main()
{
    vector<int> v = {4, 3, 2, 1, 4};
    Solution S;
    S.maxArea(v);
    return 0;
}