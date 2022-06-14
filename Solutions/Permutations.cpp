#include <bits/stdc++.h>

using namespace std;

class Solution
{
  public:
    vector<vector<int>> res;
    void get(vector<int> cur, set<int> wait)
    {
        if (wait.empty())
        {
            res.push_back(cur);
        }
        for (auto wait_element : wait)
        {
            vector<int> next_cur = cur;
            next_cur.push_back(wait_element);
            set<int> wait_cur = wait;
            wait_cur.erase(wait_element);
            get(next_cur, wait_cur);
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<int> cur;
        set<int> wait;
        for (auto nums_element : nums)
        {
            wait.insert(nums_element);
        };
        get(cur, wait);
        return res;
    }
};