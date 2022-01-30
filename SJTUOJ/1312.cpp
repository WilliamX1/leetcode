#include <iostream>

using namespace std;

int main()
{
    int N; cin >> N;
    int n, k;
    for (int i = 0; i < N; i++)
    {
        cin >> n >> k;
        if (k == 1)
        {
            if (n % 2 == 0) cout << "Yeah!" << endl;
            else cout << "5555" << endl;
        }
        else
        {
            if (n <= k) cout << "5555" << endl;
            else cout << "Yeah!" << endl;
        }
    }
    return 0;
}
