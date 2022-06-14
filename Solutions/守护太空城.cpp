class Solution
{
  public:
    struct node
    {
        int time;
        int position;
        node(){};
        node(int time, int position) : time(time), position(position)
        {
        }
    };
    int defendSpaceCity(vector<int> &time, vector<int> &position)
    {
        vector<node> v;
        int n = time.size();
        for (int i = 0; i < n; i++)
        {
            v.push_back(node(time[i], position[i]));
        };
        sort(v.begin(), v.end(), [](const node &v1, const node &v2) { return v1.time < v2.time; });

        unordered_map<int, int> opentime;
        int i = 0, ans = 0;

        while (i < n)
        {
            set<int> s;
            int curtime = v[i].time;
            s.insert(v[i].position);
            while (++i < n && v[i].time == curtime)
            {
                s.insert(v[i].position);
            };
            vector<int> pos;
            for (const int &ele : s)
            {
                if (!opentime[ele])
                    pos.push_back(ele);
            };
            sort(pos.begin(), pos.end());
            int possize = pos.size();
            for (int i = 0; i < possize; i++)
            {
                if (i + 1 < possize && pos[i] - pos[i + 1] == -1)
                {
                    ans += 3;
                    opentime[pos[i]] = opentime[pos[i + 1]] = curtime;
                    i++;
                }
                else
                {
                    ans += 2;
                    opentime[pos[i]] = curtime;
                };
            };
        };

        int tottime = v.back().time;
        for (const auto iter : opentime)
        {
            ans += tottime - iter.second;
        };
        return ans;
    }
};