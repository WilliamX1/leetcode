class Solution
{
  public:
    int minimizedMaximum(int n, vector<int> &quantities)
    {
        sort(quantities.begin(), quantities.end());
        int left = 1, right = *max_element(quantities.begin(), quantities.end());
        while (left <= right)
        {
            int mid = (left + right) >> 1, cnt = 0;
            for (const int &q : quantities)
                cnt += (q - 1) / mid + 1;
            if (cnt > n)
                left = mid + 1;
            else
                right = mid - 1;
        };
        return left;
    }
};