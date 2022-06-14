/* rand example: guess the number */
#include <stdio.h>  /* printf, scanf, puts, NULL */
#include <stdlib.h> /* srand, rand */
#include <time.h>   /* time */

class Solution
{
  public:
    vector<vector<int>> rects;
    vector<int> preSum;
    int upper;
    Solution(vector<vector<int>> &rects)
    {
        int n = rects.size();
        this->rects = rects;
        this->preSum = vector<int>(n);
        for (int i = 0; i < n; i++)
        {
            const vector<int> &r = rects[i];
            int a = r[0], b = r[1], x = r[2], y = r[3];
            this->preSum[i] = (x - a + 1) * (y - b + 1);
        };
        for (int i = 1; i < this->preSum.size(); i++)
            this->preSum[i] += this->preSum[i - 1];
        upper = this->preSum.back();
        srand(time(NULL));
    };

    vector<int> pick()
    {
        int r = rand() % upper;

        int i = upper_bound(preSum.begin(), preSum.end(), r) - preSum.begin();
        if (i > 0)
            r -= preSum[i - 1];
        int a = rects[i][0], b = rects[i][1], x = rects[i][2], y = rects[i][3];
        int xx = a + r % (x - a + 1), yy = b + r / (x - a + 1);
        return {xx, yy};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */