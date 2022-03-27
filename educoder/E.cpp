#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int k, n; cin >> k >> n;
    for (int i = 0; i < n; i++) {
        k += min(k / 10, 5) + 5;
    };
    cout << k << endl;
    return 0;
}