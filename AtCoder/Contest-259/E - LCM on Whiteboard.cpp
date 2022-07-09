#include <iostream>
#include <set>
#include <stdio.h>
#include <unordered_map>
#include <vector>

using namespace std;

int main()
{
    int N;
    scanf("%d", &N);

    unordered_map<int, int> first, second;

    vector<vector<vector<int>>> nums(N);

    int m, p, e;
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &m);
        for (int j = 0; j < m; j++)
        {
            scanf("%d%d", &p, &e);
            nums[i].push_back({p, e});

            if (e >= first[p])
            {
                second[p] = first[p];
                first[p] = e;
            }
            else if (e > second[p])
                second[p] = e;
        };
    };

    vector<int> keys, values;
    unordered_map<int, int> num2index;
    for (auto &iter : first)
    {
        keys.push_back(iter.first);
        values.push_back(iter.second);
    };
    for (int i = 0; i < keys.size(); i++)
        num2index[keys[i]] = i;

    vector<int> v = values;

    set<vector<int>> s;
    set<vector<vector<int>>> the_same;
    for (int i = 0; i < N; i++)
    {
        if (the_same.count(nums[i]))
            continue;
        the_same.insert(nums[i]);

        m = nums[i].size();

        for (int j = 0; j < m; j++)
        {
            p = nums[i][j][0], e = nums[i][j][1];
            if (e == first[p])
                v[num2index[p]] = second[p];
        };
        s.insert(v);
        for (int j = 0; j < m; j++)
        {
            int p = nums[i][j][0], e = nums[i][j][1];
            if (e == first[p])
                v[num2index[p]] = first[p];
        };
    };
    cout << s.size() << endl;

    return 0;
}