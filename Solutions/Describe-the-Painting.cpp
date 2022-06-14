#include <unordered_set>
#include <vector>

using namespace std;

class Solution
{
  public:
    vector<vector<long long>> splitPainting(vector<vector<int>> &segments)
    {
        const int N = 1e5;
        vector<long long> res(N + 1);
        unordered_map<int, bool> board;
        for (const vector<int> &seg : segments)
        {
            int left = seg[0], right = seg[1], color = seg[2];
            res[left] += (long long)color;
            res[right] -= (long long)color;

            board[left] = board[right] = true;
        };
        for (int i = 1; i <= N; i++)
        {
            res[i] += res[i - 1];
        };
        vector<vector<long long>> ans;
        int left = 0, right = 0;
        while (left <= N)
        {
            left = right;
            while (left <= N && res[left] == 0)
                left++;
            right = left + 1;
            while (right <= N && res[right] == res[right - 1] && !board[right])
                right++;

            if (right <= N)
            {
                ans.push_back({left, right, res[left]});
            };
        };
        return ans;
    }
};