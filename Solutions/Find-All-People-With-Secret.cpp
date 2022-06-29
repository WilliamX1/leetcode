class Solution
{
  public:
    class UnionSet
    {
        unordered_map<int, int> father, rank;

      public:
        UnionSet(set<int> &s)
        {
            for (const int &num : s)
            {
                father[num] = num;
                rank[num] = 1;
            };
        };
        int find(int x)
        {
            return x == father[x] ? x : find(father[x]);
        };
        void to_union(int x, int y)
        {
            int fa_x = find(x);
            int fa_y = find(y);

            if (rank[fa_x] > rank[fa_y])
            {
                father[fa_y] = fa_x;
                rank[fa_x] += rank[fa_y];
            }
            else
            {
                father[fa_x] = fa_y;
                rank[fa_y] += rank[fa_x];
            };
        };
    };
    vector<int> findAllPeople(int n, vector<vector<int>> &meetings, int firstPerson)
    {
        sort(meetings.begin(), meetings.end(), [](const vector<int> &a, const vector<int> &b) { return a[2] < b[2]; });

        set<int> s;
        s.insert(0);
        s.insert(firstPerson);

        int left = 0, right = 0, m = meetings.size();
        while (left < m)
        {
            while (right < m && meetings[right][2] == meetings[left][2])
                right++;

            // cout << left << ' ' << right << endl;
            bool flag;

            set<int> ss;

            for (int i = left; i < right; i++)
            {
                ss.insert(meetings[i][0]);
                ss.insert(meetings[i][1]);
            };

            UnionSet uni(ss);

            for (int i = left; i < right; i++)
                uni.to_union(meetings[i][0], meetings[i][1]);

            set<int> know;
            for (const int &num : ss)
                if (s.count(num))
                    know.insert(uni.find(num));

            for (const int &num : ss)
                if (know.count(uni.find(num)))
                    s.insert(num);

            left = right;
        };
        vector<int> ret;
        for (const int &e : s)
            ret.push_back(e);
        return ret;
    }
};