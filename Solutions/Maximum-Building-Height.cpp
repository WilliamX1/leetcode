class Solution
{
  public:
    int maxBuilding(int n, vector<vector<int>> &restrictions)
    {
        restrictions.push_back({1, 0});
        sort(restrictions.begin(), restrictions.end(),
             [](const vector<int> &a, const vector<int> &b) { return a[0] < b[0]; });
        if (restrictions.back()[0] != n)
            restrictions.push_back({n, n - 1});
        int ans = 0, size = restrictions.size();
        for (int i = 1; i < size; i++)
        {
            restrictions[i][1] =
                min(restrictions[i][1], restrictions[i - 1][1] + restrictions[i][0] - restrictions[i - 1][0]);
        };

        for (int i = size - 2; i >= 0; i--)
            restrictions[i][1] =
                min(restrictions[i][1], restrictions[i + 1][1] + restrictions[i + 1][0] - restrictions[i][0]);

        for (int i = 1; i < size; i++)
        {
            int cnt =
                ((restrictions[i][0] - restrictions[i - 1][0]) - abs(restrictions[i][1] - restrictions[i - 1][1])) / 2;
            ans = max(ans, max(restrictions[i - 1][1], restrictions[i][1]) + cnt);
        };
        return ans;
    }
};