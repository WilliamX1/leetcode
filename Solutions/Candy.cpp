#include <iostream>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> dpleft(n, 0), dpright(n, 0);
        dpleft[0] = dpright[n - 1] = 1;
        for (int i = 1; i < n; i++)
            dpleft[i] = ratings[i] > ratings[i - 1] ? dpleft[i - 1] + 1 : 1;
        for (int i = n - 2; i >= 0; i--)
            dpright[i] = ratings[i] > ratings[i + 1] ? dpright[i + 1] + 1 : 1;
        int tot = 0;
        for (int i = 0; i < n; i++)
            tot += max(dpleft[i], dpright[i]);
        return tot;
    }
};