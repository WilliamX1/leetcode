#include <algorithm>
#include <iostream>
#include <set>
#include <stdio.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        scanf("%d", &n);
        vector<int> a(n + 1), b(n + 1);
        unordered_map<int, set<int>> val2index, bbbb;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            val2index[a[i]].insert(i);
        };
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &b[i]);
            bbbb[b[i]].insert(i);
        };

        int ans = 1e9;
        for (auto &iter : val2index)
        {
            int val = iter.first, cnt = 0;
            set<int> pre = iter.second;

            while (pre.size() < n)
            {
                set<int> next;
                for (const int &index : pre)
                {
                    for (const int &snum : bbbb[index])
                    {
                        if (!pre.count(snum))
                        {
                            next.insert(snum);
                        };
                    };
                };

                if (next.empty())
                    break;
                else
                {
                    cnt += next.size();
                    for (const int &num : next)
                        pre.insert(num);
                };
            };
            if (pre.size() == n)
                ans = min(ans, cnt);
        }

        cout << (ans == 1e9 ? -1 : ans) << endl;
    };
    return 0;
}