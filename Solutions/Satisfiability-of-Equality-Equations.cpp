class Solution
{
    class UnionSet
    {
        unordered_map<string, string> father;
        unordered_map<string, int> rank;

      public:
        UnionSet(const set<string> &v)
        {
            for (const string &str : v)
            {
                father[str] = str;
                rank[str] = 1;
            };
        };

        string find(const string &str)
        {
            return str == father[str] ? str : find(father[str]);
        };

        void to_union(const string &str1, const string &str2)
        {
            string str1_fa = find(str1), str2_fa = find(str2);
            int rank1 = rank[str1_fa], rank2 = rank[str2_fa];
            if (rank1 >= rank2)
            {
                father[str2_fa] = str1_fa;
                rank[str1_fa] += rank2;
            }
            else
            {
                father[str1_fa] = str2_fa;
                rank[str2_fa] += rank1;
            };
        };

        bool is_connect(const string &str1, const string &str2)
        {
            return find(str1) == find(str2);
        };
    };

  public:
    bool equationsPossible(vector<string> &equations)
    {
        set<string> s;
        vector<bool> isEqual;
        vector<vector<string>> v;
        for (const string &equa : equations)
        {
            string str1, str2;
            int i = 0;

            while (i < equa.size() && 'a' <= equa[i] && equa[i] <= 'z')
                str1.push_back(equa[i++]);

            if (equa[i] == '=')
                isEqual.push_back(true);
            else
                isEqual.push_back(false);
            while (i < equa.size() && (equa[i] < 'a' || equa[i] > 'z'))
                i++;

            while (i < equa.size() && 'a' <= equa[i] && equa[i] <= 'z')
                str2.push_back(equa[i++]);

            s.insert(str1);
            s.insert(str2);
            v.push_back({str1, str2});
        };
        UnionSet uni(s);
        for (int i = 0; i < equations.size(); i++)
            if (isEqual[i] && v[i][0] != v[i][1])
                uni.to_union(v[i][0], v[i][1]);
        for (int i = 0; i < equations.size(); i++)
            if (!isEqual[i] && uni.is_connect(v[i][0], v[i][1]))
                return false;
        return true;
    }
};