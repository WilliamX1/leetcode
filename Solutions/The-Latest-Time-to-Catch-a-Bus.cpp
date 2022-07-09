class Solution
{
  public:
    int latestTimeCatchTheBus(vector<int> &buses, vector<int> &passengers, int capacity)
    {
        sort(buses.begin(), buses.end());
        sort(passengers.begin(), passengers.end());

        unordered_map<int, int> flags;
        for (const int &pass : passengers)
            flags[pass] = true;

        int bus_num = buses.size(), pass_num = passengers.size(), pass_idx = 0;
        vector<vector<int>> v(bus_num);

        for (int i = 0; i < bus_num; i++)
        {
            int cap = capacity;
            while (pass_idx < pass_num && passengers[pass_idx] <= buses[i] && cap--)
                v[i].push_back(passengers[pass_idx++]);
        };

        int ans = v.back().size() < capacity ? buses.back() : v.back().back();
        while (flags[ans])
            ans--;

        return ans;
    }
};