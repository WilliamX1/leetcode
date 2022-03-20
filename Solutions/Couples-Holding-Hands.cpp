class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int tot = 0;
        for (int i = 0; i < row.size(); i += 2) {
            if (row[i] / 2 != row[i + 1] / 2) {
                for (int j = i + 2; j < row.size(); j++) {
                    if (row[i] / 2 == row[j] / 2) {
                        swap(row[i + 1], row[j]);
                    };
                };
                tot++;
            };
        };
        return tot;
    }
};