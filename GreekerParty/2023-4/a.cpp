# include <iostream>
# include <stdio.h>
# include <vector>

using namespace std;

int main()
{
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);

    int64_t n;
    cin >> n;
    cout << ((n & 1) ? "ying" : "jiani") << endl;
    return 0;
}