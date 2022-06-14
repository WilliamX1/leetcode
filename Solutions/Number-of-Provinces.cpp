#include <unordered_set>
#include <vector>

using namespace std;

class Solution
{
  public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size(), tot = 0, idx = 0;
        unordered_set<int> U;

        while (U.size() < n)
        {
            unordered_set<int> s1, s2;
            s1.insert(idx++);
            while (!s1.empty())
            {
                int x = *s1.begin();
                s1.erase(s1.begin());

                if (!s2.count(x))
                {
                    for (int i = 0; i < n; i++)
                        if (isConnected[x][i])
                            s1.insert(i);
                };

                s2.insert(x);
            };
            U.insert(s2.begin(), s2.end());
            tot++;

            while (idx < n && U.count(idx))
                idx++;
        };
        return tot;
    };
};