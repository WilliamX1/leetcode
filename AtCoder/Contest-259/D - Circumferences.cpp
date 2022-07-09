#include <iostream>
#include <set>
#include <unordered_set>
#include <vector>

using namespace std;

class UnionSet
{
    vector<int64_t> father;
    vector<int64_t> rank;

  public:
    UnionSet(int64_t N)
    {
        father = vector<int64_t>(N);
        for (int64_t i = 0; i < N; i++)
            father[i] = i;
        rank = vector<int64_t>(N, 1);
    };

    int64_t find(int64_t x)
    {
        return x == father[x] ? x : find(father[x]);
    };

    void to_union(int64_t x, int64_t y)
    {
        int64_t fa_x = find(x), fa_y = find(y);
        if (fa_x == fa_y)
            return;
        else if (rank[fa_x] > rank[fa_y])
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

    bool is_connect(int64_t x, int64_t y)
    {
        return find(x) == find(y);
    };
};

int main()
{
    int64_t N;
    cin >> N;

    int64_t sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;

    set<vector<int64_t>> c;
    vector<vector<int64_t>> circles(N, vector<int64_t>(4));
    vector<int64_t> circle(4);
    for (int64_t i = 0; i < N; i++)
    {
        cin >> circle[0] >> circle[1] >> circle[2];
        if (!c.count(circle))
        {
            c.insert(circle);
            circles.push_back(circle);
        };
    };

    N = circles.size();

    UnionSet s(N);

    for (int64_t i = 0; i < N; i++)
        for (int64_t j = 0; j < N; j++)
        {
            int64_t x1 = circles[i][0], y1 = circles[i][1], r1 = circles[i][2], x2 = circles[j][0], y2 = circles[j][1],
                    r2 = circles[j][2];
            int64_t dis = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
            if (i != j && (r1 - r2) * (r1 - r2) <= dis && dis <= (r1 + r2) * (r1 + r2))
                s.to_union(i, j);
        };

    bool flag = false;
    set<int64_t> havebeen;
    for (int64_t i = 0; i < N; i++)
    {
        int64_t father = s.find(i);
        if ((sx - circles[i][0]) * (sx - circles[i][0]) + (sy - circles[i][1]) * (sy - circles[i][1]) ==
            circles[i][2] * circles[i][2])
        {
            if (havebeen.count(father))
            {
                flag = true;
                break;
            };
            havebeen.insert(father);
        }
        if ((tx - circles[i][0]) * (tx - circles[i][0]) + (ty - circles[i][1]) * (ty - circles[i][1]) ==
            circles[i][2] * circles[i][2])
        {
            if (havebeen.count(father))
            {
                flag = true;
                break;
            };
            havebeen.insert(father);
        }
    };

    cout << (flag ? "Yes" : "No") << endl;

    return 0;
}