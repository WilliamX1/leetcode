#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution
{
    unordered_map<int, int> fa, size;
    int groups, maxSize = 0;

    int find(int x)
    {
        return fa[x] != x ? fa[x] = find(fa[x]) : x;
    };

    void merge(int x, int y)
    {
        if (!fa.count(y))
            return;
        x = find(x);
        y = find(y);
        if (x == y)
            return;
        fa[x] = y;
        size[y] += size[x];
        maxSize = max(maxSize, size[y]);
        --groups;
    };

  public:
    vector<int> groupStrings(vector<string> &words)
    {
        groups = words.size();
        for (auto &word : words)
        {
            int x = 0;
            for (char ch : word)
            {
                x |= 1 << (ch - 'a');
            };
            fa[x] = x;
            ++size[x];
            maxSize = max(maxSize, size[x]);
            if (size[x] > 1)
                --groups;
        };

        for (auto &[x, _] : fa)
        {
            for (int i = 0; i < 26; i++)
            {
                merge(x, x ^ (1 << i));
                if ((x >> i) & 1)
                {
                    for (int j = 0; j < 26; j++)
                    {
                        if (((x >> j) & 1) == 0)
                        {
                            merge(x, x ^ (1 << i) | (1 << j));
                        };
                    };
                };
            };
        };
        return {groups, maxSize};
    }
}