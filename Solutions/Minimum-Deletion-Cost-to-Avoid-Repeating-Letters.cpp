#include <bits/stdc++.h>

using namespace std;

class Solution
{
  public:
    int minCost(string s, vector<int> &cost)
    {
        priority_queue<int, vector<int>, greater<int>> p;
        p.push(cost[0]);
        int n = s.length(), res = 0;
        for (int i = 1; i < n; i++)
        {
            if (s[i] == s[i - 1])
                p.push(cost[i]);
            else
            {
                int m = p.size();
                while (--m > 0)
                {
                    res += p.top();
                    p.pop();
                };
                p.pop();
                p.push(cost[i]);
            }
        };
        int m = p.size();
        while (--m > 0)
        {
            res += p.top();
            p.pop();
        };
        p.pop();
        return res;
    }
};