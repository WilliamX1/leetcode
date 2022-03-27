#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool OK(const vector<int>& nums, const int& n, int eps) {
    vector<int> lower(n), upper(n);
    for (int i = 0; i < n; i++) {
        lower[i] = max(1, nums[i] - eps);
        upper[i] = nums[i] + eps;
    };
    int start = lower[0];
    for (int i = 1; i < n; i++) {
        if (start + 1 <= upper[i]) start = max(lower[i], start + 1);
        else return false;
    };
    return true;
};

int main()
{
    int n; cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    int left = 1, right = 1e9 + 7;
    while (left <= right) {
        int mid = (left + right) >> 1;
        if (OK(nums, n, mid)) right = mid - 1;
        else left = mid + 1;
    };
    cout << right + 1 << endl;
    return 0;
}