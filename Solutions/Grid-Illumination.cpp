#include <map>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
  public:
    vector<int> gridIllumination(int n, vector<vector<int>> &lamps, vector<vector<int>> &queries)
    {
        unordered_map<int, int> rows, cols, left_point, right_point;

        /* 去重 */
        set<vector<int>> s;
        for (int i = 0; i < lamps.size(); i++)
            s.insert(lamps[i]);
        for (set<vector<int>>::iterator iter = s.begin(); iter != s.end(); iter++)
        {
            vector<int> tmp = *iter;
            int row = tmp[0], col = tmp[1];
            rows[row]++;
            cols[col]++;
            left_point[row + col]++;
            right_point[row - col]++;
        };

        vector<int> ans;
        for (int i = 0; i < queries.size(); i++)
        {
            int row = queries[i][0], col = queries[i][1];
            vector<int> index;
            index.push_back(row);
            index.push_back(col);
            if (rows[row] > 0 || cols[col] > 0 || left_point[row + col] > 0 || right_point[row - col] > 0)
                ans.push_back(1);
            else
                ans.push_back(0);

            for (int j = -1; j <= 1; j++)
                for (int k = -1; k <= 1; k++)
                {
                    vector<int> tmp;
                    tmp.push_back(row + j);
                    tmp.push_back(col + k);
                    if (s.find(tmp) != s.end())
                    {
                        s.erase(s.find(tmp));
                        rows[row + j]--;
                        cols[col + k]--;
                        left_point[row + j + col + k]--;
                        right_point[row + j - (col + k)]--;
                    }
                };
        };
        return ans;
    };
};