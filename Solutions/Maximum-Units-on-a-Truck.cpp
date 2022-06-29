class Solution
{
  public:
    int maximumUnits(vector<vector<int>> &boxTypes, int truckSize)
    {
        sort(boxTypes.begin(), boxTypes.end(), [](const vector<int> &a, const vector<int> &b) { return a[1] > b[1]; });
        int ans = 0;
        for (const vector<int> &v : boxTypes)
        {
            int cnt = v[0], num = v[1];
            if (cnt <= truckSize)
            {
                truckSize -= cnt;
                ans += cnt * num;
            }
            else
            {
                ans += truckSize * num;
                break;
            };
        };
        return ans;
    }
};