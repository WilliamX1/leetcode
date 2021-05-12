#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        // 前缀异或
        int n = arr.size();
        vector<int> prefix(n, 0);
        if (n > 0) prefix[0] = arr[0];
        for (int i = 1; i < n; i++) prefix[i] = arr[i] ^ prefix[i - 1];

        int m = queries.size();
        int limit = m - 1;
        vector<int> res(m, 0);
        int i, j;
        for (i = 0; i < limit; i += 2)
        {
            res[i] = prefix[queries[i][0]] ^ prefix[queries[i][1]] ^ arr[queries[i][0]];
            j = i + 1;
            res[j] = prefix[queries[j][0]] ^ prefix[queries[j][1]] ^ arr[queries[j][0]];
        }
        for (; i < m; i++)
            res[i] = prefix[queries[i][0]] ^ prefix[queries[i][1]] ^ arr[queries[i][0]];

        return res;
    }
};

int main()
{
    vector<int> arr = {16};
    vector<vector<int>> queries = {{0,0}, {0,0}, {0,0}};
    Solution S;
    S.xorQueries(arr, queries);

    return 0;
}