class Solution
{
  public:
    long long maximumImportance(int n, vector<vector<int>> &roads)
    {
        unordered_map<int, int> counts;
        for (vector<int> &road : roads)
        {
            counts[road[0]]++;
            counts[road[1]]++;
        };
        vector<vector<int>> v;
        for (auto iter : counts)
        {
            v.push_back({iter.first, iter.second});
        };
        sort(v.begin(), v.end(), [](const vector<int> &a, const vector<int> &b) { return a[1] > b[1]; });
        int64_t ans = 0;
        for (int i = 0; i < v.size(); i++)
        {
            ans += (int64_t)v[i][1] * (int64_t)(n - i);
        };
        return ans;
    }
};