#include <iostream>

using namespace std;

int main()
{
    int N; cin >> N;

    long long int V, a, b;

    while(N-- > 0)
    {
        cin >> V >> a >> b;
        if (b >= 2 * a)
            cout << a * V << endl;
        else
            if (V % 2 == 0)
                cout << b * V / 2 << endl;
            else
                cout << V / 2 * b + a << endl;
    }
    return 0;
}
