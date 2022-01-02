class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> prev(rowIndex, 1), next(rowIndex + 1, 1);
        for (int i = 2; i <= rowIndex; i++) {
            prev = next;
            for (int j = 1; j < i; j++) {
                next[j] = prev[j - 1] + prev[j];
            };
        };
        return next;
    }
};