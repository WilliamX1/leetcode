#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> edges(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        edges[u].push_back(v);
        edges[v].push_back(u);
    };

    vector<int> havebeen(n + 1, false);
    int tot = 0;

    for (int i = 1; i <= n; i++)
    {
        if (havebeen[i] || edges[i].size() != 2)
            continue;

        int last = i, next = edges[i][0];
        havebeen[last] = true;

        while (!havebeen[next])
        {
            if (edges[next].size() != 2)
                break;
            else if (edges[next][0] != last)
            {
                last = next;
                next = edges[next][0];
                havebeen[last] = true;
            }
            else if (edges[next][1] != last)
            {
                last = next;
                next = edges[next][1];
                havebeen[last] = true;
            };
        };
        tot += next == i;
    };
    cout << tot << endl;
    return 0;
}