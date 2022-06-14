class Solution
{
  public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        vector<int> v;
        int len1 = m, len2 = n, idx1 = 0, idx2 = 0;
        while (idx1 < len1 && idx2 < len2)
        {
            if (nums1[idx1] < nums2[idx2])
                v.push_back(nums1[idx1++]);
            else
                v.push_back(nums2[idx2++]);
        };
        while (idx1 < len1)
            v.push_back(nums1[idx1++]);
        while (idx2 < len2)
            v.push_back(nums2[idx2++]);
        nums1 = v;
        return;
    };
};