class Solution
{
  public:
    int xorAllNums(vector<int> &nums1, vector<int> &nums2)
    {
        int ans1 = 0, ans2 = 0;
        for (const int &num : nums1)
            ans1 ^= num;
        for (const int &num : nums2)
            ans2 ^= num;

        return (nums1.size() & 1 ? ans2 : 0) ^ (nums2.size() & 1 ? ans1 : 0);
    }
};