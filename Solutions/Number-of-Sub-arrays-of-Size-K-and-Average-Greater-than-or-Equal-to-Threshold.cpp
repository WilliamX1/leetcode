class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int tot = 0, ans = 0;
        for (int i = 0; i < k; i++)
            tot += arr[i];
        if (tot >= k * threshold) ans++;
        for (int i = k; i < arr.size(); i++) {
            tot += arr[i] - arr[i - k];
            if (tot >= k * threshold) ans++;
        };
        return ans;
    }
};