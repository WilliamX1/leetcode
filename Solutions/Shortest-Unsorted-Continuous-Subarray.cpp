#include <bits/stdc++.h>

using namespace std;

class Solution
{
  public:
    struct node
    {
        int val;
        int idx;
        node(){};
        node(int v, int i) : val(v), idx(i){};
    };
    int findUnsortedSubarray(vector<int> &nums)
    {
        vector<node> v;
        int len = nums.size();
        for (int i = 0; i < len; i++)
            v.push_back(node(nums[i], i));
        sort(v.begin(), v.end(),
             [](const node &a, const node &b) { return a.val == b.val ? a.idx < b.idx : a.val < b.val; });
        int L = 0x7fffffff, R = -1;
        for (int i = 0; i < len; i++)
            if (v[i].idx == i)
                continue;
            else
            {
                L = min(L, min(i, v[i].idx));
                R = max(R, max(i, v[i].idx));
            };
        return L == 0x7fffffff ? 0 : R - L + 1;
    }
};