
class Union
{
    vector<int> fa;
    vector<int> rank;
    unordered_map<int, int> r;
    int m;

  public:
    Union(int n, int m)
    {
        this->m = m;
        fa = vector<int>(n + 2);
        for (int i = 0; i <= n; i++)
            fa[i] = i;
        rank = vector<int>(n + 2, 0);
    };
    int find(int x)
    {
        return fa[x] == x ? x : find(fa[x]);
    };
    void connect(int ma, int so)
    {
        int f1 = find(ma), f2 = find(so);
        if (rank[f1] && rank[f2])
        {
            r[rank[f1]]--;
            r[rank[f2]]--;
            if (rank[f1] > rank[f2])
            {
                fa[f2] = f1;
                rank[f1] += rank[f2];
                r[rank[f1]]++;
            }
            else
            {
                fa[f1] = f2;
                rank[f2] += rank[f1];
                r[rank[f2]]++;
            };
        };
    };
    void setrank(int ma)
    {
        rank[ma] = 1;
        r[rank[ma]]++;
    };
    bool OK()
    {
        return r[m];
    };
};

class Solution
{
  public:
    int findLatestStep(vector<int> &arr, int m)
    {
        Union un(arr.size(), m);
        int ans = -1;
        for (int i = 0; i < arr.size(); i++)
        {
            un.setrank(arr[i]);
            un.connect(arr[i], arr[i] - 1);
            un.connect(arr[i], arr[i] + 1);
            if (un.OK())
                ans = i + 1;
        };
        return ans;
    }
};