class Solution
{
  public:
    int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
    {
        int n = startTime.size();
        vector<vector<int>> v(n);
        for (int i = 0; i < n; i++)
            v[i] = {startTime[i], endTime[i], profit[i]};
        sort(v.begin(), v.end(), [](const vector<int> &a, const vector<int> &b) { return a[1] < b[1]; });

        int ans = 0;
        map<int, int> m;
        m[0] = 0;
        for (const vector<int> &vv : v)
        {
            int start = vv[0], end = vv[1], p = vv[2];
            auto iter1 = m.upper_bound(start);
            iter1--;
            auto iter2 = m.upper_bound(end);
            iter2--;
            m[end] = max(iter2->second, p + iter1->second);
            ans = max(ans, m[end]);
        };
        return ans;
    }
};