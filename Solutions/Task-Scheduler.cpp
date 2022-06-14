#include <bits/stdc++.h>

using namespace std;

class Solution
{
  public:
    int leastInterval(vector<char> &tasks, int n)
    {
        sort(tasks.begin(), tasks.end());
        map<char, int> m;
        for (auto task : tasks)
        {
            auto iter = m.find(task);
            if (iter != m.end())
                iter->second++;
            else
                m.insert(make_pair(task, 1));
        };
        int tar = -1, cnt = 0;
        auto iter = m.begin();
        while (iter != m.end())
        {
            if (iter->second > tar)
            {
                tar = iter->second;
                cnt = 1;
            }
            else if (iter->second == tar)
                cnt++;
            iter++;
        };
        return max(int(tasks.size()), (tar - 1) * (n + 1) + cnt);
    }
};