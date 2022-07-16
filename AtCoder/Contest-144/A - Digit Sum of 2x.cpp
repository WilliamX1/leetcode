#include <cstring>
#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;

    cout << 2 * N << endl << (N % 4 ? to_string(N % 4) : "") + string(N / 4, '4') << endl;
    return 0;
}