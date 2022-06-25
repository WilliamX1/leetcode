class Solution
{
  public:
    int minimumTeachings(int n, vector<vector<int>> &languages, vector<vector<int>> &friendships)
    {
        int m = languages.size();
        set<int> s;
        for (const vector<int> &f : friendships)
        {
            int u = f[0], v = f[1];
            bool flag = false;
            // cout << u << ' ' << v << endl;
            for (const int &j : languages[u - 1])
            {
                for (const int &k : languages[v - 1])
                {
                    if (j == k)
                    {
                        flag = true;
                        break;
                    };
                };
            };
            if (!flag)
            {
                s.insert(u);
                s.insert(v);
            };
        };
        // cout << "here" << endl;
        vector<int> v(n + 1, 0);
        for (const int &uv : s)
            for (const int &j : languages[uv - 1])
                v[j]++;
        return s.size() - *max_element(v.begin(), v.end());
    }
};