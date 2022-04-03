class Solution {
public:
    bool OK(const vector<int>& candies, int mid, long long k) {
        for (const int& c : candies) {
            k -= c / mid;
        };
        return k <= 0;
    };
    int maximumCandies(vector<int>& candies, long long k) {
        int left = 1, right = 1e7 + 1, mid;
        while (left <= right) {
            mid = (left + right) >> 1;
            if (OK(candies, mid, k)) left = mid + 1;
            else right = mid - 1;
        };
        return right;
    }
};