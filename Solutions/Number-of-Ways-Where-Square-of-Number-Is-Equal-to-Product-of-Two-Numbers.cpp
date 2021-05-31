#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        unordered_map<int64_t, int> nums1_square, nums2_square, nums1_mul, nums2_mul;
        for (int i = 0; i < n1; i++) {
            int64_t tmp = int64_t(nums1[i]) * int64_t(nums1[i]);
            auto iter = nums1_square.find(tmp);
            if (iter != nums1_square.end()) {
                iter->second++;
            } else nums1_square.insert(make_pair(tmp, 1));
        }
        for (int i = 0; i < n2; i++) {
            int64_t tmp = int64_t(nums2[i]) * int64_t(nums2[i]);
            auto iter = nums2_square.find(tmp);
            if (iter != nums2_square.end()) {
                iter->second++;
            } else nums2_square.insert(make_pair(tmp, 1));
        }

        for (int i = 0; i < n1; i++) {
            for (int j = i + 1; j < n1; j++) {
                int64_t tmp = int64_t(nums1[i]) * int64_t(nums1[j]);
                auto iter = nums1_mul.find(tmp);
                if (iter != nums1_mul.end()) {
                    iter->second++;
                } else nums1_mul.insert(make_pair(tmp, 1));
            }
        };
        for (int i = 0; i < n2; i++) {
            for (int j = i + 1; j < n2; j++) {
                int64_t tmp = int64_t(nums2[i]) * int64_t(nums2[j]);
                auto iter = nums2_mul.find(tmp);
                if (iter != nums2_mul.end()) {
                    iter->second++;
                } else nums2_mul.insert(make_pair(tmp, 1));
            }
        };

        int res = 0;
        auto iter = nums1_square.begin();
        while (iter != nums1_square.end()) {
            if (nums2_mul.find(iter->first) != nums2_mul.end()) {
                res += iter->second * nums2_mul.find(iter->first)->second;
            };
            iter++;
        };
        iter = nums2_square.begin();
        while (iter != nums2_square.end()) {
            if (nums1_mul.find(iter->first) != nums1_mul.end()) {
                res += iter->second * nums1_mul.find(iter->first)->second;
            };
            iter++;
        };

        return res;
    }
};

int main()
{
    vector<int> nums1 = {100000, 100000}, nums2 = {50000, 200000};
    Solution S;
    S.numTriplets(nums1, nums2);
    return 0;
}