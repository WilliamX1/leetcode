class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> v;
        if (original.size() == m * n) {
            int start = 0, idx = 0;
            while (idx++ < m) {
                vector<int> cur; cur.assign(original.begin() + start, original.begin() + start + n);
                v.push_back(cur);
                start += n;
            };
        };
        return v;
    }
};