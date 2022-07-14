class Solution
{
    class UnionSet
    {
        unordered_map<int, int> fathers;
        unordered_map<int, int> ranks;

      public:
        UnionSet(set<int> &s)
        {
            for (const int &num : s)
            {
                fathers[num] = num;
                ranks[num] = 1;
            };
        };
        int find(int x)
        {
            return x == fathers[x] ? x : find(fathers[x]);
        };
        void to_union(int x, int y)
        {
            int fa_x = find(x), fa_y = find(y);
            if (fa_x == fa_y)
                return;
            else if (ranks[fa_x] >= ranks[fa_y])
            {
                fathers[fa_y] = fa_x;
                ranks[fa_x] += ranks[fa_y];
            }
            else
            {
                fathers[fa_x] = fa_y;
                ranks[fa_y] += ranks[fa_x];
            };
        };
        bool is_connect(int x, int y)
        {
            return find(x) == find(y);
        };
    };

  public:
    int removeStones(vector<vector<int>> &stones)
    {
        set<int> s;
        unordered_map<int, vector<int>> rows, columns;
        for (const vector<int> &num : stones)
        {
            s.insert(num[0] * 1e5 + num[1]);
            rows[num[0]].push_back(num[1]);
            columns[num[1]].push_back(num[0]);
        };

        UnionSet u(s);
        for (auto iter : rows)
        {
            int x = iter.first;
            if (!iter.second.empty())
            {
                int y = iter.second[0];
                for (const int &another_y : iter.second)
                    u.to_union(x * 1e5 + y, x * 1e5 + another_y);
            };
        };
        for (auto iter : columns)
        {
            int y = iter.first;
            if (!iter.second.empty())
            {
                int x = iter.second[0];
                for (const int &another_x : iter.second)
                    u.to_union(x * 1e5 + y, another_x * 1e5 + y);
            }
        }
        set<int> ss;
        for (const int &num : s)
            ss.insert(u.find(num));
        return stones.size() - ss.size();
    }
};