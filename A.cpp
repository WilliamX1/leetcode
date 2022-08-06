#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main()
{
    int k, n;
    cin >> k >> n;
    vector<string> v1(n);
    for (int i = 0; i < n; i++)
        cin >> v1[i];
    int m;
    cin >> m;
    vector<string> v2(m);
    for (int i = 0; i < m; i++)
        cin >> v2[i];
    int q;
    cin >> q;
    set<string> v3;
    for (int i = 0; i < q; i++)
    {
        string tmp;
        cin >> tmp;
        v3.insert(tmp);
    };

    set<string> s;
    int i = 0, cnt = 0;
    while (i < v1.size() && cnt < k)
    {
        if (!s.count(v1[i]) && v3.count(v1[i]))
        {
            s.insert(v1[i]);
            cnt++;
        };
        i++;
    };
    i = 0, cnt = 0;
    while (i < v2.size() && cnt < k)
    {
        if (!s.count(v2[i]) && v3.count(v2[i]))
        {
            s.insert(v2[i]);
            cnt++;
        };
        i++;
    };
    cout << s.size() << endl;
    for (const string &str : s)
        cout << str << endl;
    return 0;
}