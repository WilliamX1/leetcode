#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int s = 0, x = 0, tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        s += tmp;
        x = min(x, s);
    };
    cout << s - x << endl;
    return 0;
}