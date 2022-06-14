class Solution
{
  public:
    vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2)
    {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int ptr1 = 0, ptr2 = 0, n1 = nums1.size(), n2 = nums2.size();
        vector<vector<int>> answer(2);
        while (ptr1 < n1 && ptr2 < n2)
        {
            if (nums1[ptr1] == nums2[ptr2])
            {
                ++ptr1;
                while (ptr1 < n1 && nums1[ptr1] == nums1[ptr1 - 1])
                    ptr1++;
                ++ptr2;
                while (ptr2 < n2 && nums2[ptr2] == nums2[ptr2 - 1])
                    ptr2++;
            }
            else if (nums1[ptr1] < nums2[ptr2])
            {
                answer[0].push_back(nums1[ptr1++]);
                while (ptr1 < n1 && nums1[ptr1] == nums1[ptr1 - 1])
                    ptr1++;
            }
            else if (nums2[ptr2] < nums1[ptr1])
            {
                answer[1].push_back(nums2[ptr2++]);
                while (ptr2 < n2 && nums2[ptr2] == nums2[ptr2 - 1])
                    ptr2++;
            }
            else
            {
                // impossible
            };
        };
        while (ptr1 < n1)
        {
            answer[0].push_back(nums1[ptr1++]);
            while (ptr1 < n1 && nums1[ptr1] == nums1[ptr1 - 1])
                ptr1++;
        }
        while (ptr2 < n2)
        {
            answer[1].push_back(nums2[ptr2++]);
            while (ptr2 < n2 && nums2[ptr2] == nums2[ptr2 - 1])
                ptr2++;
        }
        return answer;
    }
};