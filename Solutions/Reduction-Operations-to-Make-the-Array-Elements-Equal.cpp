#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    int reductionOperations(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        if (size == 1)
            return 0;

        int ans = 0, cnt = 1;
        int start = 1;
        while (start < size && nums[start] == nums[start - 1])
            start++;

        int next_start = start + 1;

        while (start < size)
        {
            while (next_start < size && nums[next_start] == nums[next_start - 1])
                next_start++;
            ans += (next_start - start) * cnt;
            cnt++;
            start = next_start;
            next_start++;
        };
        return ans;
    }
};

int main()
{
    vector<int> v = {1, 1, 1};
    Solution S;
    std::cout << S.reductionOperations(v);
    return 0;
}