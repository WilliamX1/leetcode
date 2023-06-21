class Solution {
public:
    vector<int> supplyWagon(vector<int>& supplies) {
        int n = supplies.size();

        while (supplies.size() > n / 2) {
            int index = -1, total = 0x7fffffff;
            for (int i = 0; i < supplies.size() - 1; i++) {
                if (supplies[i] + supplies[i + 1] < total) {
                    index = i;
                    total = supplies[i] + supplies[i + 1];
                };
            };
            supplies[index] = total;
            supplies.erase(supplies.begin() + index + 1);
        };
        return supplies;
    }
};