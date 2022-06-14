class Solution
{
  private:
    vector<int> counts;
    vector<vector<int>> tmp;
    void _countSmaller(vector<vector<int>> &arr, int l, int r)
    {
        if (r - l == 0)
            return;

        int m = (l + r) >> 1;
        if (m > l)
            _countSmaller(arr, l, m);
        if (r > m + 1)
            _countSmaller(arr, m + 1, r);

        int ptr = m + 1;
        for (int i = l; i <= m; i++)
        {
            while (ptr <= r && arr[ptr][0] < arr[i][0])
                ptr++;
            counts[arr[i][1]] += ptr - (m + 1);
        };

        int ptr1 = l, ptr2 = m + 1, size = 0;
        while (ptr1 <= m && ptr2 <= r)
        {
            if (arr[ptr1][0] < arr[ptr2][0])
                tmp[size++] = arr[ptr1++];
            else
                tmp[size++] = arr[ptr2++];
        };
        while (ptr1 <= m)
            tmp[size++] = arr[ptr1++];
        while (ptr2 <= r)
            tmp[size++] = arr[ptr2++];
        for (int i = 0; i < size; i++)
            arr[l + i] = tmp[i];
        return;
    };

  public:
    vector<int> countSmaller(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> arr;
        for (int i = 0; i < n; i++)
            arr.push_back({nums[i], i});
        counts = vector<int>(n, 0);
        tmp = vector<vector<int>>(n);
        _countSmaller(arr, 0, n - 1);
        return counts;
    };
};