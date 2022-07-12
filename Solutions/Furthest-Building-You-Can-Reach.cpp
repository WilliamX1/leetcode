class Solution
{
  public:
    int furthestBuilding(vector<int> &heights, int bricks, int ladders)
    {
        int left = 0, n = heights.size(), right = n - 1;
        while (left <= right)
        {
            int mid = (left + right) >> 1;
            vector<int> v;
            for (int i = 1; i <= mid; i++)
                if (heights[i] > heights[i - 1])
                    v.push_back(heights[i] - heights[i - 1]);
            sort(v.begin(), v.end());
            int b = bricks, i = 0;
            while (b > 0 && i < v.size())
            {
                if (b >= v[i])
                {
                    b -= v[i];
                    i++;
                }
                else
                    break;
            };

            if (v.size() - i <= ladders)
                left = mid + 1;
            else
                right = mid - 1;
        };
        return right;
    }
};