#include <cstring>
#include <iostream>

using namespace std;

int main()
{
    int N, Q;
    cin >> N >> Q;
    string str;
    cin >> str;

    int ch, x, tail = N - 1;
    for (int i = 0; i < Q; i++)
    {
        cin >> ch >> x;
        if (ch == 1)
            tail = (tail - x + N) % N;
        else if (ch == 2)
            cout << str[(tail + x) % N] << endl;
    };
    return 0;
}