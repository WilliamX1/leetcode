#include <iostream>

using namespace std;

int main()
{
    int n1, n2, n3; cin >> n1 >> n2 >> n3;
    int sum = 0;
    n1 += n2;

    for (int i = 1; i <= n3; i++)
    {
        cin >> n2;
        if (n2 <= n1) ++sum;
    }
    cout << sum;
    return 0;
}
