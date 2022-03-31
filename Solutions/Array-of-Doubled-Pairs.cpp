class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        unordered_map<int, int> count;
        for (int i = 0; i < arr.size(); i++)
            count[arr[i]]++;
        sort(arr.begin(), arr.end());
        for (int i = 0; i < arr.size(); i++) {
            if (!count[arr[i]]) continue;
            if (arr[i] < 0) {
                if ((arr[i] & 1) || count[arr[i] >> 1] < count[arr[i]]) return false;
                else {
                    count[arr[i] >> 1] -= count[arr[i]];
                    count[arr[i]] = 0;
                };
            } else if (arr[i] == 0) {
                count[arr[i]] = 0;
            } else if (arr[i] > 0) {
                if (count[arr[i] << 1] < count[arr[i]]) return false;
                else {
                    count[arr[i] << 1] -= count[arr[i]];
                    count[arr[i]] = 0;
                };
            } else {};
        };
        for (const auto ele : count)
            if (ele.second) return false;
        return true;
    }
};