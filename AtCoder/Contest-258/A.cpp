#include <iostream>

using namespace std;

int main()
{
    int K;
    cin >> K;
    if (K < 10)
        cout << "21:0" + to_string(K) << endl;
    else if (K < 60)
        cout << "21:" + to_string(K) << endl;
    else if (K < 70)
        cout << "22:0" + to_string(K - 60) << endl;
    else
        cout << "22:" + to_string(K - 60) << endl;
    return 0;
}