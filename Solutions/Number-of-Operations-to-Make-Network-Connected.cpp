#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
  public:
    int groups = 0;
    int more = 0;
    unordered_map<int, int> fathers;
    int find(int x)
    {
        return fathers[x] == x ? x : find(fathers[x]);
    };
    void init(int n)
    {
        for (int i = 0; i < n; i++)
            fathers[i] = i;
        groups = n;
    };
    int add(int x, int y)
    {
        x = find(x);
        y = find(y);

        if (x == y)
            more++;
        else
        {
            fathers[x] = y;
            groups--;
        };
        return y;
    }

    int makeConnected(int n, vector<vector<int>> &connections)
    {
        init(n);
        for (int i = 0; i < connections.size(); i++)
        {
            add(connections[i][0], connections[i][1]);
        };
        return more >= groups - 1 ? groups - 1 : -1;
    }
};