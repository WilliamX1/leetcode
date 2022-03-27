#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    int ans = v[0];
    for (int i = 1; i < n; i++)
        ans = max(ans, v[i]);
    cout << ans << endl;
    return 0;
}