#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n; cin >> n;
    int N = 50;
    vector<string> ans;
    for (int i = 1; i < 100; i++)
        if (i <= n)
            ans.push_back(to_string(i) + ".mp4");

    int base = 10;
    for (int i = 0; i < 8; i++) {
        base *= 10;
        for (int j = base; j <= base + 100; j++)
            if (j <= n)
                ans.push_back(to_string(j) + ".mp4");
    };
    sort(ans.begin(), ans.end(), less<string>());
    for (int i = 0; i < N; i++)
        cout << ans[i] << endl;
    return 0;
}

// int main()
// {
//     vector<int> v;
//     for (int i = 1; i < 10000; i++)
//         v.push_back(i);
//     sort(v.begin(), v.end(), [](const int& a, const int& b) {
//         return to_string(a) < to_string(b);
//     });
//     for (int i = 0; i < v.size(); i++)
//         cout << v[i] << endl;
//     return 0;
// }