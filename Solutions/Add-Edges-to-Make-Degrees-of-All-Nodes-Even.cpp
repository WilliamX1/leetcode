class Solution
{
  public:
    bool isPossible(int n, vector<vector<int>> &edges)
    {
        set<vector<int>> edge_set;
        unordered_map<int, int> count;
        for (vector<int> &edge : edges)
        {
            count[edge[0]]++;
            count[edge[1]]++;
            edge_set.insert({edge[0], edge[1]});
            edge_set.insert({edge[1], edge[0]});
        };
        vector<int> v;
        for (auto &[e, c] : count)
            if (c & 1)
                v.push_back(e);

        int size = v.size();
        cout << size << endl;
        if (size == 0)
            return true;
        else if (size == 2)
        {
            if (!edge_set.count({v[0], v[1]}))
                return true;
            for (int i = 1; i <= n; i++)
                if (i != v[0] && i != v[1] && !edge_set.count({i, v[0]}) && !edge_set.count({i, v[1]}))
                    return true;
            return false;
        }
        else if (size == 4)
        {
            for (int i1 = 0; i1 < size; i1++)
                for (int i2 = 0; i2 < size; i2++)
                    for (int i3 = 0; i3 < size; i3++)
                        for (int i4 = 0; i4 < size; i4++)
                            if (i1 != i2 && i1 != i3 && i1 != i4 && i2 != i3 && i2 != i4 && i3 != i4 &&
                                !edge_set.count({v[i1], v[i2]}) && !edge_set.count({v[i3], v[i4]}))
                                return true;
            return false;
        }
        else
            return false;
    }
};