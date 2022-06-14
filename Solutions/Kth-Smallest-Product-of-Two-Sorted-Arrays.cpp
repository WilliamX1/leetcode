class Solution
{
  public:
    struct cmp
    {
        bool operator()(const vector<int64_t> &a, const vector<int64_t> &b) const
        {
            return a[0] > b[0];
        };
    };
    long long kthSmallestProduct(vector<int> &nums1, vector<int> &nums2, long long k)
    {
        priority_queue<vector<int64_t>, vector<vector<int64_t>>, cmp> pque;
        int n1 = nums1.size(), n2 = nums2.size();
        for (int i = 0; i < n1; ++i)
            if (nums1[i] >= 0)
                pque.push({(int64_t)nums1[i] * (int64_t)nums2.front(), i, 0});
            else
                pque.push({(int64_t)nums1[i] * (int64_t)nums2.back(), i, (int64_t)nums2.size() - 1});
        while (--k > 0)
        {
            vector<int64_t> t = pque.top();
            pque.pop();

            int idx1 = t[1], idx2 = t[2];
            if (nums1[idx1] >= 0 && idx2 + 1 < n2)
            {

                while (idx2 + 1 < n2 - 1 && nums2[idx2 + 1] == nums2[idx2] && k > 1)
                {
                    k--;
                    idx2++;
                }
                pque.push({(int64_t)nums1[idx1] * (int64_t)nums2[++idx2], idx1, idx2});
            }
            else if (nums1[idx1] < 0 && idx2 - 1 >= 0)
            {
                while (idx2 - 1 >= 0 + 1 && nums2[idx2 - 1] == nums2[idx2] && k > 1)
                {
                    k--;
                    idx2--;
                };
                pque.push({(int64_t)nums1[idx1] * (int64_t)nums2[--idx2], idx1, idx2});
            }
            else
            {
            };
        };
        return pque.top()[0];
    }
};