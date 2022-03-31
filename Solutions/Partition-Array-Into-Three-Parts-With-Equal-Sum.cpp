class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int tot = 0;
        for (const int& ele : arr)
            tot += ele;
        if (tot % 3 != 0) return false;
        else tot /= 3;

        int tmp = 0, cnt = 0;
        for (int i = 0; i < arr.size(); i++) {
            tmp += arr[i];
            if (tmp == tot) {
                tmp = 0;
                cnt++;
            };
        };
        return cnt >= 3;
    }
};