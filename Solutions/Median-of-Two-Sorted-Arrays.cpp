#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        /*暴力合并数组*/
        vector<int> _merge;
        int iter1 = 0, iter2 = 0, len1 = nums1.size(), len2 = nums2.size();
        while (iter1 < len1 && iter2 < len2) {
            if (nums1[iter1] < nums2[iter2]) {
                _merge.push_back(nums1[iter1]);
                iter1++;
            } else {
                _merge.push_back(nums2[iter2]);
                iter2++;
            };
        };
        while (iter1 < len1) {
            _merge.push_back(nums1[iter1]);
            iter1++;
        };
        while (iter2 < len2) {
            _merge.push_back(nums2[iter2]);
            iter2++;
        };
        int len = _merge.size();
        if (len & 1 == 1) return double(_merge[len >> 1]);
        else return double((_merge[len >> 1] + _merge[-1 + len >> 1])) / 2;
    }
};