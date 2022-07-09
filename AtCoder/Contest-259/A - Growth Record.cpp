#include <iostream>

using namespace std;

int main()
{
    int N, M, X, T, D;
    cin >> N >> M >> X >> T >> D;

    cout << (M >= X ? T : T - (X - M) * D) << endl;
    return 0;
}