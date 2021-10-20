#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int _findKthLargest(vector<int>& arr, int k, int l, int r) {
        int idx = l - 1;
        for (int i = l; i < r; i++)
            if (arr[i] > arr[r]) swap(arr[i], arr[++idx]);
        swap(arr[++idx], arr[r]);

        if (idx == k) return arr[idx];
        else return idx < k? _findKthLargest(arr, k, idx + 1, r) : _findKthLargest(arr, k, l, idx - 1);
    };
public:
    int findKthLargest(vector<int>& nums, int k) {
        --k;
        return _findKthLargest(nums, k, 0, nums.size() - 1);
    };
};