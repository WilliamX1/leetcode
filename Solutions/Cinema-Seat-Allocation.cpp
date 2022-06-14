class Solution
{
  public:
    int maxNumberOfFamilies(int n, vector<vector<int>> &reservedSeats)
    {
        set<int> s;
        unordered_map<int, set<int>> m;
        for (int i = 0; i < reservedSeats.size(); i++)
        {
            s.insert(reservedSeats[i][0]);
            set<int> v;
            if (m.find(reservedSeats[i][0]) != m.end())
                v = m[reservedSeats[i][0]];
            v.insert(reservedSeats[i][1]);
            m[reservedSeats[i][0]] = v;
        };
        int ans = (n - s.size()) * 2;
        for (auto line : s)
        {
            set<int> v = m[line];
            if (v.find(2) == v.end() && v.find(3) == v.end() && v.find(4) == v.end() && v.find(5) == v.end() &&
                v.find(6) == v.end() && v.find(7) == v.end() && v.find(8) == v.end() && v.find(9) == v.end())
                ans += 2;
            else if (v.find(2) == v.end() && v.find(3) == v.end() && v.find(4) == v.end() && v.find(5) == v.end())
                ans++;
            else if (v.find(6) == v.end() && v.find(7) == v.end() && v.find(8) == v.end() && v.find(9) == v.end())
                ans++;
            else if (v.find(4) == v.end() && v.find(5) == v.end() && v.find(6) == v.end() && v.find(7) == v.end())
                ans++;
            else
            {
            };
        };
        return ans;
    }
};