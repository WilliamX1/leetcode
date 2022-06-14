class Solution
{
  public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        stack<int> s;
        unordered_map<int, int> m;
        int len1 = nums1.size(), len2 = nums2.size();
        for (int i = len2 - 1; i >= 0; i--)
        {
            while (!s.empty() && nums2[i] > s.top())
                s.pop();
            m[nums2[i]] = s.empty() ? -1 : s.top();
            s.push(nums2[i]);
        };

        vector<int> v(len1, -1);
        for (int i = 0; i < len1; i++)
            v[i] = m[nums1[i]];
        return v;
    }
};