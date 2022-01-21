#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int l = 1e6, t = -1e6, r = -1e6, b = 1e6;
    int x1, y1, x2, y2;

    int n; cin >> n;
    while(n--)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        l = min(l, x1);
        l = min(l, x2);
        r = max(r, x1);
        r = max(r, x2);
        t = max(t, y1);
        t = max(t, y2);
        b = min(b, y1);
        b = min(b, y2);
    }

    cout << (t - b) * (r - l);
    return 0;
}
