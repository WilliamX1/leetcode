class Solution
{
    class UnionSet
    {
        vector<int> fathers;
        vector<int> ranks;

      public:
        UnionSet(int N)
        {
            fathers = vector<int>(N);
            for (int i = 0; i < N; i++)
                fathers[i] = i;
            ranks = vector<int>(N, 1);
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

        int get_rank(int x)
        {
            return ranks[find(x)];
        };
    };

  public:
    int validSubarraySize(vector<int> &nums, int threshold)
    {
        int n = nums.size();

        vector<vector<int>> v;
        for (int i = 0; i < n; i++)
            v.push_back({threshold / nums[i] + 1, i});

        sort(v.begin(), v.end(), [](const vector<int> &a, const vector<int> &b) { return a[0] < b[0]; });

        UnionSet uni(n);
        vector<bool> havebeen(n, false);
        int i = 0, j;
        while (i < n)
        {
            j = i;
            while (j < n && v[j][0] == v[i][0])
            {
                int index = v[j][1];
                havebeen[index] = true;
                if (index && havebeen[index - 1])
                    uni.to_union(index, index - 1);
                if (index < n - 1 && havebeen[index + 1])
                    uni.to_union(index, index + 1);

                if (uni.get_rank(v[j][1]) >= v[j][0])
                    return uni.get_rank(v[j][1]);
                j++;
            };
            i = j;
        };
        return -1;
    }
};