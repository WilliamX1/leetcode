#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
  public:
    int maxCandies(vector<int> &status, vector<int> &candies, vector<vector<int>> &keys,
                   vector<vector<int>> &containedBoxes, vector<int> &initialBoxes)
    {
        int n = status.size(), tot = 0;
        vector<bool> have_key(n, false);
        while (!initialBoxes.empty())
        {
            int idx = -1;
            for (int i = 0; i < initialBoxes.size(); i++)
            {
                if (status[initialBoxes[i]] || have_key[initialBoxes[i]])
                {
                    idx = i;
                    break;
                };
            };
            // cout << idx << ' ';
            if (idx == -1)
                break;
            else
            {
                int b = initialBoxes[idx];
                tot += candies[b];
                for (const int &key : keys[b])
                    have_key[key] = true;
                initialBoxes.erase(initialBoxes.begin() + idx);
                for (const int &box : containedBoxes[b])
                    initialBoxes.push_back(box);
            };
        };
        return tot;
    }
};